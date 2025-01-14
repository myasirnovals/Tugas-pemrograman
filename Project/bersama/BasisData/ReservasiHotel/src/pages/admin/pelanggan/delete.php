<?php
require_once '../../../config/config.php';

if ($_SERVER['REQUEST_METHOD'] !== 'POST' || !isset($_POST['id_pelanggan'])) {
    header('Location: pelanggan.php?status=error&message=Invalid Request');
    exit;
}

$id_pelanggan = $_POST['id_pelanggan'];

try {
    $conn->beginTransaction();

    // 1. Cek apakah pelanggan memiliki reservasi
    $check_query = "SELECT id_reservasi FROM reservasi WHERE id_pelanggan = :id";
    $check_stmt = $conn->prepare($check_query);
    $check_stmt->execute(['id' => $id_pelanggan]);
    $reservasi_ids = $check_stmt->fetchAll(PDO::FETCH_COLUMN);

    if (!empty($reservasi_ids)) {
        // 2. Hapus data pembayaran terkait
        $delete_pembayaran = "DELETE FROM pembayaran WHERE id_reservasi IN (" .
            str_repeat('?,', count($reservasi_ids) - 1) . '?)';
        $stmt_pembayaran = $conn->prepare($delete_pembayaran);
        $stmt_pembayaran->execute($reservasi_ids);

        // 3. Hapus data kamar terkait
        $delete_kamar = "DELETE FROM kamar WHERE id_reservasi IN (" .
            str_repeat('?,', count($reservasi_ids) - 1) . '?)';
        $stmt_kamar = $conn->prepare($delete_kamar);
        $stmt_kamar->execute($reservasi_ids);

        // 4. Hapus reservasi
        $delete_reservasi = "DELETE FROM reservasi WHERE id_pelanggan = :id";
        $stmt_reservasi = $conn->prepare($delete_reservasi);
        $stmt_reservasi->execute(['id' => $id_pelanggan]);
    }

    // 5. Dapatkan kode_alamat sebelum menghapus pelanggan
    $get_alamat_query = "SELECT kode_alamat FROM pelanggan WHERE id_pelanggan = :id";
    $stmt_get_alamat = $conn->prepare($get_alamat_query);
    $stmt_get_alamat->execute(['id' => $id_pelanggan]);
    $kode_alamat = $stmt_get_alamat->fetchColumn();

    // 6. Hapus data pelanggan
    $delete_pelanggan = "DELETE FROM pelanggan WHERE id_pelanggan = :id";
    $stmt_pelanggan = $conn->prepare($delete_pelanggan);
    $stmt_pelanggan->execute(['id' => $id_pelanggan]);

    // 7. Hapus data alamat
    if ($kode_alamat) {
        $delete_alamat = "DELETE FROM alamat WHERE kode_alamat = :kode";
        $stmt_alamat = $conn->prepare($delete_alamat);
        $stmt_alamat->execute(['kode' => $kode_alamat]);
    }

    $conn->commit();
    header('Location: pelanggan.php?status=success&message=Data pelanggan berhasil dihapus');
    exit;

} catch (PDOException $e) {
    $conn->rollBack();
    header('Location: pelanggan.php?status=error&message=Gagal menghapus data: ' . $e->getMessage());
    exit;
}
?>
