<?php
session_start();
require_once "config/config.php";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    try {
        $conn->beginTransaction();

        if (empty($_POST['nama_lengkap']) || empty($_POST['email']) ||
            empty($_POST['no_telepon']) || empty($_POST['alamat']) ||
            empty($_POST['tanggal_check_in']) || empty($_POST['tanggal_check_out']) ||
            empty($_POST['tipe_kamar']) || empty($_POST['jumlah_kamar']) ||
            empty($_POST['metode_pembayaran'])) {
            throw new Exception("Semua field harus diisi!");
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

        $queryAlamat = "INSERT INTO alamat (kode_alamat, jalan) VALUES (:kode_alamat, :jalan)";
        $stmtAlamat = $conn->prepare($queryAlamat);

        $kodeAlamat = 'A' . str_pad(rand(1, 999), 3, '0', STR_PAD_LEFT);
        $stmtAlamat->execute([
            ':kode_alamat' => $kodeAlamat,
            ':jalan' => $_POST['alamat']
        ]);

        $queryPelanggan = "INSERT INTO pelanggan (nama_pelanggan, kode_alamat, no_hp, email) 
                          VALUES (:nama, :kode_alamat, :no_hp, :email)";
        $stmtPelanggan = $conn->prepare($queryPelanggan);
        $stmtPelanggan->execute([
            ':nama' => $_POST['nama_lengkap'],
            ':kode_alamat' => $kodeAlamat,
            ':no_hp' => $_POST['no_telepon'],
            ':email' => $_POST['email']
        ]);

        $idPelanggan = $conn->lastInsertId();

        $queryReservasi = "INSERT INTO reservasi (id_pelanggan, tanggal_checkin, tanggal_checkout, status) 
                          VALUES (:id_pelanggan, :checkin, :checkout, 'Pending')";
        $stmtReservasi = $conn->prepare($queryReservasi);
        $stmtReservasi->execute([
            ':id_pelanggan' => $idPelanggan,
            ':checkin' => $_POST['tanggal_check_in'],
            ':checkout' => $_POST['tanggal_check_out']
        ]);

        $idReservasi = $conn->lastInsertId();

        $queryCheckKamar = "SELECT COUNT(*) as available FROM kamar 
                           WHERE id_tipe = :id_tipe 
                           AND status = 'Available'";
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

function validateInput($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
?>
