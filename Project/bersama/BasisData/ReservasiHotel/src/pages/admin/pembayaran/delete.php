<?php
require_once '../../../config/config.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['id_pembayaran'])) {
    try {
        $conn->beginTransaction();

        $queryGetReservasi = "SELECT id_reservasi FROM pembayaran WHERE id_pembayaran = :id_pembayaran";
        $stmtGetReservasi = $conn->prepare($queryGetReservasi);
        $stmtGetReservasi->execute([':id_pembayaran' => $_POST['id_pembayaran']]);
        $id_reservasi = $stmtGetReservasi->fetchColumn();

        if ($id_reservasi) {
            $queryUpdateReservasi = "UPDATE reservasi SET status = 'Pending' WHERE id_reservasi = :id_reservasi";
            $stmtUpdateReservasi = $conn->prepare($queryUpdateReservasi);
            $stmtUpdateReservasi->execute([':id_reservasi' => $id_reservasi]);

            $queryDelete = "DELETE FROM pembayaran WHERE id_pembayaran = :id_pembayaran";
            $stmtDelete = $conn->prepare($queryDelete);
            $stmtDelete->execute([':id_pembayaran' => $_POST['id_pembayaran']]);

            $conn->commit();

            header('Location: pembayaran.php?status=success&message=Data pembayaran berhasil dihapus');
            exit;
        } else {
            throw new Exception("Data pembayaran tidak ditemukan");
        }
    } catch (Exception $e) {
        $conn->rollBack();
        header('Location: pembayaran.php?status=error&message=' . urlencode($e->getMessage()));
        exit;
    }
} else {
    header('Location: pembayaran.php?status=error&message=Invalid Request');
    exit;
}
