<?php
// Delete Function
if (isset($_POST['delete'])) {
    $id = $_POST['id_pelanggan'];

    try {
        $stmt = $conn->prepare("DELETE FROM pelanggan WHERE id_pelanggan = ?");
        $stmt->execute([$id]);
        header("Location: pelanggan.php?status=success&message=Data berhasil dihapus");
    } catch (PDOException $e) {
        header("Location: pelanggan.php?status=error&message=Gagal menghapus data");
    }
}