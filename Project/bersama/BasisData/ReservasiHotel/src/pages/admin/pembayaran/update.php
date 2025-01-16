<?php
session_start();

if (!isset($_SESSION['user_id']) || !isset($_SESSION['role']) || $_SESSION['role'] !== 'admin') {
    header("Location: ../../../index.php");
    exit();
}

require_once '../../../config/config.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        $conn->beginTransaction();

        $query = "UPDATE pembayaran 
                 SET kode_mp = :kode_mp,
                     total_bayar = :total_bayar,
                     tanggal_pembayaran = :tanggal_pembayaran
                 WHERE id_pembayaran = :id_pembayaran";

        $stmt = $conn->prepare($query);
        $stmt->execute([
            ':kode_mp' => $_POST['kode_mp'],
            ':total_bayar' => $_POST['total_bayar'],
            ':tanggal_pembayaran' => $_POST['tanggal_pembayaran'],
            ':id_pembayaran' => $_POST['id_pembayaran']
        ]);

        $queryReservasi = "UPDATE reservasi r 
                          JOIN pembayaran p ON r.id_reservasi = p.id_reservasi
                          SET r.status = :status 
                          WHERE p.id_pembayaran = :id_pembayaran";

        $stmtReservasi = $conn->prepare($queryReservasi);
        $stmtReservasi->execute([
            ':status' => $_POST['status'],
            ':id_pembayaran' => $_POST['id_pembayaran']
        ]);

        $conn->commit();

        header('Location: pembayaran.php?status=success&message=Data pembayaran berhasil diupdate');
        exit;
    } catch (PDOException $e) {
        $conn->rollBack();
        header('Location: pembayaran.php?status=error&message=' . urlencode($e->getMessage()));
        exit;
    }
}
