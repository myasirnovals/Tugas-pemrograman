<?php
require_once '../../../config/config.php';

if ($_SERVER['REQUEST_METHOD'] !== 'POST' || !isset($_POST['id_reservasi'])) {
    header('Location: reservasi.php?status=error&message=Invalid Request');
    exit;
}

$id_reservasi = $_POST['id_reservasi'];

try {
    $conn->beginTransaction();

    $delete_pembayaran = "DELETE FROM pembayaran WHERE id_reservasi = :id";
    $stmt_pembayaran = $conn->prepare($delete_pembayaran);
    $stmt_pembayaran->execute(['id' => $id_reservasi]);

    $update_kamar = "UPDATE kamar SET id_reservasi = NULL WHERE id_reservasi = :id";
    $stmt_kamar = $conn->prepare($update_kamar);
    $stmt_kamar->execute(['id' => $id_reservasi]);

    $delete_reservasi = "DELETE FROM reservasi WHERE id_reservasi = :id";
    $stmt_reservasi = $conn->prepare($delete_reservasi);
    $stmt_reservasi->execute(['id' => $id_reservasi]);

    $conn->commit();
    header('Location: reservasi.php?status=success&message=Data reservasi berhasil dihapus');
    exit;

} catch (PDOException $e) {
    $conn->rollBack();
    header('Location: reservasi.php?status=error&message=Gagal menghapus data: ' . $e->getMessage());
    exit;
}
?>
