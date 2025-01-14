<?php
require_once '../../../config/config.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        // Validasi input
        if (!isset($_POST['id_kamar']) || empty($_POST['id_kamar'])) {
            throw new Exception("ID Kamar tidak valid");
        }

        $id_kamar = trim($_POST['id_kamar']);

        // Validasi ID numerik
        if (!is_numeric($id_kamar)) {
            throw new Exception("ID Kamar tidak valid");
        }

        // Cek apakah kamar masih ada
        $check_query = "SELECT status FROM kamar WHERE id_kamar = :id_kamar";
        $check_stmt = $conn->prepare($check_query);
        $check_stmt->execute(['id_kamar' => $id_kamar]);
        $kamar = $check_stmt->fetch(PDO::FETCH_ASSOC);

        if (!$kamar) {
            throw new Exception("Data kamar tidak ditemukan");
        }

        // Cek apakah kamar sedang digunakan (Occupied atau Reserved)
        if (in_array($kamar['status'], ['Occupied', 'Reserved'])) {
            throw new Exception("Tidak dapat menghapus kamar yang sedang digunakan atau direservasi");
        }

        // Begin transaction
        $conn->beginTransaction();

        // Hapus data kamar
        $query = "DELETE FROM kamar WHERE id_kamar = :id_kamar";
        $stmt = $conn->prepare($query);
        $stmt->execute(['id_kamar' => $id_kamar]);

        // Commit transaction
        $conn->commit();

        // Redirect dengan pesan sukses
        header('Location: kamar.php?status=success&message=Data kamar berhasil dihapus');
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
