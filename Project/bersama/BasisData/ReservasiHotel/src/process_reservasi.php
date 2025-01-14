<?php
session_start();
require_once "config/config.php";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    try {
        $conn->beginTransaction();

        // Validasi input
        if (empty($_POST['nama_lengkap']) || empty($_POST['email']) ||
            empty($_POST['no_telepon']) || empty($_POST['alamat']) ||
            empty($_POST['tanggal_check_in']) || empty($_POST['tanggal_check_out']) ||
            empty($_POST['tipe_kamar']) || empty($_POST['jumlah_kamar']) ||
            empty($_POST['metode_pembayaran'])) {
            throw new Exception("Semua field harus diisi!");
        }

        // Validasi tanggal
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

        // 1. Insert data alamat
        $queryAlamat = "INSERT INTO alamat (kode_alamat, jalan) VALUES (:kode_alamat, :jalan)";
        $stmtAlamat = $conn->prepare($queryAlamat);

        $kodeAlamat = 'A' . str_pad(rand(1, 999), 3, '0', STR_PAD_LEFT);
        $stmtAlamat->execute([
            ':kode_alamat' => $kodeAlamat,
            ':jalan' => $_POST['alamat']
        ]);

        // 2. Insert data pelanggan
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

        // 3. Insert data reservasi
        $queryReservasi = "INSERT INTO reservasi (id_pelanggan, tanggal_checkin, tanggal_checkout, status) 
                          VALUES (:id_pelanggan, :checkin, :checkout, 'Pending')";
        $stmtReservasi = $conn->prepare($queryReservasi);
        $stmtReservasi->execute([
            ':id_pelanggan' => $idPelanggan,
            ':checkin' => $_POST['tanggal_check_in'],
            ':checkout' => $_POST['tanggal_check_out']
        ]);

        $idReservasi = $conn->lastInsertId();

        // 4. Cek ketersediaan kamar
        $queryCheckKamar = "SELECT COUNT(*) as available FROM kamar 
                           WHERE id_tipe = :id_tipe 
                           AND status = 'Available'";
        $stmtCheckKamar = $conn->prepare($queryCheckKamar);
        $stmtCheckKamar->execute([':id_tipe' => $_POST['tipe_kamar']]);
        $available = $stmtCheckKamar->fetch(PDO::FETCH_ASSOC)['available'];

        if ($available < $_POST['jumlah_kamar']) {
            throw new Exception("Maaf, kamar tidak tersedia untuk jumlah yang diminta!");
        }

        // 5. Update status kamar dan insert data kamar
        $queryUpdateKamar = "UPDATE kamar SET status = 'Reserved', id_reservasi = :id_reservasi 
                            WHERE id_tipe = :id_tipe AND status = 'Available' 
                            LIMIT :jumlah_kamar";
        $stmtUpdateKamar = $conn->prepare($queryUpdateKamar);
        $stmtUpdateKamar->bindValue(':id_reservasi', $idReservasi);
        $stmtUpdateKamar->bindValue(':id_tipe', $_POST['tipe_kamar']);
        $stmtUpdateKamar->bindValue(':jumlah_kamar', $_POST['jumlah_kamar'], PDO::PARAM_INT);
        $stmtUpdateKamar->execute();

        // 6. Hitung total pembayaran
        $queryHarga = "SELECT biaya FROM tipe_kamar WHERE id_tipe = :id_tipe";
        $stmtHarga = $conn->prepare($queryHarga);
        $stmtHarga->execute([':id_tipe' => $_POST['tipe_kamar']]);
        $hargaPerMalam = $stmtHarga->fetch(PDO::FETCH_ASSOC)['biaya'];

        $totalHari = $interval->days;
        $totalBayar = $hargaPerMalam * $_POST['jumlah_kamar'] * $totalHari;

        // 7. Insert data pembayaran
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

// Fungsi untuk memvalidasi input
function validateInput($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
?>
