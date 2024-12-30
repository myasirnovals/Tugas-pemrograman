<?php
// koneksi ke database
include '../../config/koneksi.php';

// cek apakah ID buku ada di URL
if (isset($_GET['id'])) {
    $buku_id = $_GET['id'];

    // query untuk menghapus data buku
    $sql = "DELETE FROM buku WHERE buku_id = '$buku_id'";

    if (mysqli_query($koneksi, $sql)) {
        echo "Data buku berhasil dihapus!";
    } else {
        echo "Terjadi kesalahan: " . mysqli_error($koneksi);
    }

    // menutup koneksi
    mysqli_close($koneksi);

    // redirect kembalil ke halaman index.php
    header("Location: index.php");
    exit();
} else {
    echo "ID buku tidak ditemukan.";
}