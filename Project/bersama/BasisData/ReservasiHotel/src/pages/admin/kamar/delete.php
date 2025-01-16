<?php
session_start();

require_once '../../../config/config.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        if (!isset($_POST['id_kamar']) || empty($_POST['id_kamar'])) {
            throw new Exception("ID Kamar tidak valid");
        }

        $id_kamar = trim($_POST['id_kamar']);

        if (!is_numeric($id_kamar)) {
            throw new Exception("ID Kamar tidak valid");
        }

        $check_query = "SELECT status FROM kamar WHERE id_kamar = :id_kamar";
        $check_stmt = $conn->prepare($check_query);
        $check_stmt->execute(['id_kamar' => $id_kamar]);
        $kamar = $check_stmt->fetch(PDO::FETCH_ASSOC);

        if (!$kamar) {
            throw new Exception("Data kamar tidak ditemukan");
        }

        if (in_array($kamar['status'], ['Occupied', 'Reserved'])) {
            throw new Exception("Tidak dapat menghapus kamar yang sedang digunakan atau direservasi");
        }

        $conn->beginTransaction();

        $query = "DELETE FROM kamar WHERE id_kamar = :id_kamar";
        $stmt = $conn->prepare($query);
        $stmt->execute(['id_kamar' => $id_kamar]);

        $conn->commit();

        header('Location: kamar.php?status=success&message=Data kamar berhasil dihapus');
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
