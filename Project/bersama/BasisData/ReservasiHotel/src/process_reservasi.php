<?php
session_start();
require_once "config/config.php";

if (!isset($_SESSION['user_id'])) {
    $_SESSION['error'] = "Anda harus login terlebih dahulu untuk melakukan reservasi!";
    header("Location: index.php#reservasi");
    exit();
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    try {
        $conn->beginTransaction();

        $required_fields = [
            'nama_pemesan', 'email', 'no_telepon',
            'jalan', 'desa', 'kota', 'provinsi', 'kode_pos',
            'tanggal_check_in', 'tanggal_check_out',
            'tipe_kamar', 'jumlah_kamar', 'metode_pembayaran'
        ];

        foreach ($required_fields as $field) {
            if (empty($_POST[$field])) {
                throw new Exception("Field {$field} harus diisi!");
            }
        }

        $checkin = new DateTime($_POST['tanggal_check_in']);
        $checkout = new DateTime($_POST['tanggal_check_out']);
        $today = new DateTime();

        if ($checkin < $today) {
            throw new Exception("Tanggal check-in tidak valid!");
        }

        $interval = $checkin->diff($checkout);
        if ($interval->days > 30) {
            throw new Exception("Maksimal menginap adalah 30 hari!");
        }

        $queryAlamat = "INSERT INTO alamat (kode_alamat, jalan, desa, kota, provinsi, kode_pos) 
                       VALUES (:kode_alamat, :jalan, :desa, :kota, :provinsi, :kode_pos)";
        $stmtAlamat = $conn->prepare($queryAlamat);

        do {
            $kodeAlamat = 'A' . str_pad(rand(1, 999), 3, '0', STR_PAD_LEFT);
            $check = $conn->query("SELECT kode_alamat FROM alamat WHERE kode_alamat = '$kodeAlamat'")->fetch();
        } while ($check);

        $stmtAlamat->execute([
            ':kode_alamat' => $kodeAlamat,
            ':jalan' => $_POST['jalan'],
            ':desa' => $_POST['desa'],
            ':kota' => $_POST['kota'],
            ':provinsi' => $_POST['provinsi'],
            ':kode_pos' => $_POST['kode_pos']
        ]);

        $queryPelanggan = "INSERT INTO pelanggan (nama_pelanggan, kode_alamat, no_hp, email, user_id) 
                          VALUES (:nama, :kode_alamat, :no_hp, :email, :user_id)";
        $stmtPelanggan = $conn->prepare($queryPelanggan);
        $stmtPelanggan->execute([
            ':nama' => $_POST['nama_pemesan'],
            ':kode_alamat' => $kodeAlamat,
            ':no_hp' => $_POST['no_telepon'],
            ':email' => $_POST['email'],
            ':user_id' => isset($_SESSION['user_id']) ? $_SESSION['user_id'] : null
        ]);

        $idPelanggan = $conn->lastInsertId();

        $queryReservasi = "INSERT INTO reservasi (id_pelanggan, nama_pemesan, tanggal_reservasi, 
                          tanggal_checkin, tanggal_checkout, status) 
                          VALUES (:id_pelanggan, :nama_pemesan, CURRENT_DATE, :checkin, :checkout, 'Pending')";
        $stmtReservasi = $conn->prepare($queryReservasi);
        $stmtReservasi->execute([
            ':id_pelanggan' => $idPelanggan,
            ':nama_pemesan' => $_POST['nama_pemesan'],
            ':checkin' => $_POST['tanggal_check_in'],
            ':checkout' => $_POST['tanggal_check_out']
        ]);

        $idReservasi = $conn->lastInsertId();

        $queryCheckKamar = "SELECT COUNT(*) as available FROM kamar 
                           WHERE id_tipe = :id_tipe AND status = 'Available'";
        $stmtCheckKamar = $conn->prepare($queryCheckKamar);
        $stmtCheckKamar->execute([':id_tipe' => $_POST['tipe_kamar']]);
        $available = $stmtCheckKamar->fetch(PDO::FETCH_ASSOC)['available'];

        if ($available < $_POST['jumlah_kamar']) {
            throw new Exception("Maaf, kamar tidak tersedia untuk jumlah yang diminta!");
        }

        $queryUpdateKamar = "UPDATE kamar SET status = 'Reserved', id_reservasi = :id_reservasi 
                            WHERE id_tipe = :id_tipe AND status = 'Available' 
                            LIMIT :jumlah_kamar";
        $stmtUpdateKamar = $conn->prepare($queryUpdateKamar);
        $stmtUpdateKamar->bindValue(':id_reservasi', $idReservasi);
        $stmtUpdateKamar->bindValue(':id_tipe', $_POST['tipe_kamar']);
        $stmtUpdateKamar->bindValue(':jumlah_kamar', $_POST['jumlah_kamar'], PDO::PARAM_INT);
        $stmtUpdateKamar->execute();

        $queryHarga = "SELECT biaya FROM tipe_kamar WHERE id_tipe = :id_tipe";
        $stmtHarga = $conn->prepare($queryHarga);
        $stmtHarga->execute([':id_tipe' => $_POST['tipe_kamar']]);
        $hargaPerMalam = $stmtHarga->fetch(PDO::FETCH_ASSOC)['biaya'];

        $totalHari = $interval->days;
        $totalBayar = $hargaPerMalam * $_POST['jumlah_kamar'] * $totalHari;

        $queryPembayaran = "INSERT INTO pembayaran (id_reservasi, kode_mp, total_bayar) 
                           VALUES (:id_reservasi, :kode_mp, :total_bayar)";
        $stmtPembayaran = $conn->prepare($queryPembayaran);
        $stmtPembayaran->execute([
            ':id_reservasi' => $idReservasi,
            ':kode_mp' => $_POST['metode_pembayaran'],
            ':total_bayar' => $totalBayar
        ]);

        $conn->commit();
        $_SESSION['success'] = "Reservasi berhasil dibuat! Total pembayaran: Rp " . number_format($totalBayar, 0, ',', '.');
        header("Location: index.php#reservasi");
        exit();

    } catch (Exception $e) {
        $conn->rollBack();
        $_SESSION['error'] = "Terjadi kesalahan: " . $e->getMessage();
        header("Location: index.php#reservasi");
        exit();
    }
}
