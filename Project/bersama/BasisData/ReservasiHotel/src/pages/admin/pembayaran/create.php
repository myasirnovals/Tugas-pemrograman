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

        $query = "INSERT INTO pembayaran (id_reservasi, kode_mp, total_bayar, tanggal_pembayaran) 
                 VALUES (:id_reservasi, :kode_mp, :total_bayar, :tanggal_pembayaran)";

        $stmt = $conn->prepare($query);
        $stmt->execute([
            ':id_reservasi' => $_POST['id_reservasi'],
            ':kode_mp' => $_POST['kode_mp'],
            ':total_bayar' => $_POST['total_bayar'],
            ':tanggal_pembayaran' => $_POST['tanggal_pembayaran']
        ]);

        $queryUpdate = "UPDATE reservasi SET status = 'Confirmed' WHERE id_reservasi = :id_reservasi";
        $stmtUpdate = $conn->prepare($queryUpdate);
        $stmtUpdate->execute([':id_reservasi' => $_POST['id_reservasi']]);

        $conn->commit();

        header('Location: pembayaran.php?status=success&message=Data pembayaran berhasil ditambahkan');
        exit;
    } catch (PDOException $e) {
        $conn->rollBack();
        header('Location: pembayaran.php?status=error&message=' . urlencode($e->getMessage()));
        exit;
    }
}
