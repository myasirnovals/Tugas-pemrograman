<?php
// koneksi ke database
include '../../config/koneksi.php';

// cek apakah ID peminjaman ada di URL
if (isset($_GET['id'])) {
    $peminjaman_id = $_GET['id'];

    // query untuk menghapus data peminjaman
    $sql = "DELETE FROM peminjaman WHERE peminjaman_id = '$peminjaman_id'";

    if (mysqli_query($koneksi, $sql)) {
        echo "Data peminjaman berhasil dihapus!";
    } else {
        echo "Terjadi kesalahan: " . mysqli_error($koneksi);
    }

    // menutup koneksi
    mysqli_close($koneksi);

    // redirect kembalil ke halaman index.php
    header("Location: index.php");
    exit();
} else {
    echo "ID peminjaman tidak ditemukan.";
}