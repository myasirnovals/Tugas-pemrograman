<?php
require_once '../../../config/config.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        // Mulai transaksi
        $conn->beginTransaction();

        // Insert data pembayaran
        $query = "INSERT INTO pembayaran (id_reservasi, kode_mp, total_bayar, tanggal_pembayaran) 
                 VALUES (:id_reservasi, :kode_mp, :total_bayar, :tanggal_pembayaran)";

        $stmt = $conn->prepare($query);
        $stmt->execute([
            ':id_reservasi' => $_POST['id_reservasi'],
            ':kode_mp' => $_POST['kode_mp'],
            ':total_bayar' => $_POST['total_bayar'],
            ':tanggal_pembayaran' => $_POST['tanggal_pembayaran']
        ]);

        // Update status reservasi menjadi Confirmed
        $queryUpdate = "UPDATE reservasi SET status = 'Confirmed' WHERE id_reservasi = :id_reservasi";
        $stmtUpdate = $conn->prepare($queryUpdate);
        $stmtUpdate->execute([':id_reservasi' => $_POST['id_reservasi']]);

        // Commit transaksi
        $conn->commit();

        // Redirect dengan pesan sukses
        header('Location: pembayaran.php?status=success&message=Data pembayaran berhasil ditambahkan');
        exit;
    } catch (PDOException $e) {
        // Rollback jika terjadi error
        $conn->rollBack();
        header('Location: pembayaran.php?status=error&message=' . urlencode($e->getMessage()));
        exit;
    }
}
