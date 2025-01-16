<?php
require_once '../../../config/config.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        $nomor_kamar = trim($_POST['nomor_kamar']);
        $id_tipe = trim($_POST['id_tipe']);
        $status = trim($_POST['status']);

        if (!preg_match("/^[0-9]{3}$/", $nomor_kamar)) {
            throw new Exception("Nomor kamar harus terdiri dari 3 digit angka");
        }

        $check_query = "SELECT COUNT(*) FROM kamar WHERE nomor_kamar = :nomor_kamar";
        $check_stmt = $conn->prepare($check_query);
        $check_stmt->execute(['nomor_kamar' => $nomor_kamar]);
        if ($check_stmt->fetchColumn() > 0) {
            throw new Exception("Nomor kamar sudah terdaftar");
        }

        $check_tipe = "SELECT COUNT(*) FROM tipe_kamar WHERE id_tipe = :id_tipe";
        $check_stmt = $conn->prepare($check_tipe);
        $check_stmt->execute(['id_tipe' => $id_tipe]);
        if ($check_stmt->fetchColumn() == 0) {
            throw new Exception("Tipe kamar tidak valid");
        }

        $valid_status = ['Available', 'Occupied', 'Reserved'];
        if (!in_array($status, $valid_status)) {
            throw new Exception("Status tidak valid");
        }

        $conn->beginTransaction();

        $query = "INSERT INTO kamar (id_tipe, nomor_kamar, status) 
                 VALUES (:id_tipe, :nomor_kamar, :status)";

        $stmt = $conn->prepare($query);
        $stmt->execute([
            'id_tipe' => $id_tipe,
            'nomor_kamar' => $nomor_kamar,
            'status' => $status
        ]);

        $conn->commit();

        header('Location: kamar.php?status=success&message=Data kamar berhasil ditambahkan');
        exit;

    } catch (Exception $e) {
        if ($conn->inTransaction()) {
            $conn->rollBack();
        }

        header('Location: kamar.php?status=error&message=' . urlencode($e->getMessage()));
        exit;
    }
} else {
    header('Location: kamar.php');
    exit;
}
?>
