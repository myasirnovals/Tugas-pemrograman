<?php
require_once '../../../config/config.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        // Validasi input
        $nomor_kamar = trim($_POST['nomor_kamar']);
        $id_tipe = trim($_POST['id_tipe']);
        $status = trim($_POST['status']);

        // Validasi nomor kamar
        if (!preg_match("/^[0-9]{3}$/", $nomor_kamar)) {
            throw new Exception("Nomor kamar harus terdiri dari 3 digit angka");
        }

        // Cek apakah nomor kamar sudah ada
        $check_query = "SELECT COUNT(*) FROM kamar WHERE nomor_kamar = :nomor_kamar";
        $check_stmt = $conn->prepare($check_query);
        $check_stmt->execute(['nomor_kamar' => $nomor_kamar]);
        if ($check_stmt->fetchColumn() > 0) {
            throw new Exception("Nomor kamar sudah terdaftar");
        }

        // Cek apakah tipe kamar valid
        $check_tipe = "SELECT COUNT(*) FROM tipe_kamar WHERE id_tipe = :id_tipe";
        $check_stmt = $conn->prepare($check_tipe);
        $check_stmt->execute(['id_tipe' => $id_tipe]);
        if ($check_stmt->fetchColumn() == 0) {
            throw new Exception("Tipe kamar tidak valid");
        }

        // Validasi status
        $valid_status = ['Available', 'Occupied', 'Reserved'];
        if (!in_array($status, $valid_status)) {
            throw new Exception("Status tidak valid");
        }

        // Begin transaction
        $conn->beginTransaction();

        // Dapatkan ID reservasi default (bisa disesuaikan dengan logika bisnis)
        $default_reservasi = 1; // Sesuaikan dengan kebutuhan

        // Insert data kamar
        $query = "INSERT INTO kamar (id_reservasi, id_tipe, nomor_kamar, status) 
                 VALUES (:id_reservasi, :id_tipe, :nomor_kamar, :status)";

        $stmt = $conn->prepare($query);
        $stmt->execute([
            'id_reservasi' => $default_reservasi,
            'id_tipe' => $id_tipe,
            'nomor_kamar' => $nomor_kamar,
            'status' => $status
        ]);

        // Commit transaction
        $conn->commit();

        // Redirect dengan pesan sukses
        header('Location: kamar.php?status=success&message=Data kamar berhasil ditambahkan');
        exit;

    } catch (Exception $e) {
        // Rollback transaction jika ada error
        if ($conn->inTransaction()) {
            $conn->rollBack();
        }

        // Redirect dengan pesan error
        header('Location: kamar.php?status=error&message=' . urlencode($e->getMessage()));
        exit;
    }
} else {
    // Jika bukan POST request, redirect ke halaman kamar
    header('Location: kamar.php');
    exit;
}
?>
