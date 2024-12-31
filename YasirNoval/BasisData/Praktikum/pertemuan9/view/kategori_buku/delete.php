<?php
// koneksi ke database
include '../../config/koneksi.php';

// cek apakah ID kategori ada di URL
if (isset($_GET['id'])) {
    $kategori_id = $_GET['id'];

    // query untuk menghapus data kategori
    $sql = "DELETE FROM kategori_buku WHERE kategori_id = '$kategori_id'";

    if (mysqli_query($koneksi, $sql)) {
        echo "Data kategori berhasil dihapus!";
    } else {
        echo "Terjadi kesalahan: " . mysqli_error($koneksi);
    }

    // menutup koneksi
    mysqli_close($koneksi);

    // redirect kembalil ke halaman index.php
    header("Location: index.php");
    exit();
} else {
    echo "ID kategori tidak ditemukan.";
}