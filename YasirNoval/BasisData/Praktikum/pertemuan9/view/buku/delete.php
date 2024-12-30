<?php
// koneksi ke database
include '../../config/koneksi.php';

// cek apakah ID anggota ada di URL
if (isset($_GET['id'])) {
    $anggota_id = $_GET['id'];

    // query untuk menghapus data anggota
    $sql = "DELETE FROM anggota WHERE anggota_id = '$anggota_id'";

    if (mysqli_query($koneksi, $sql)) {
        echo "Data anggota berhasil dihapus!";
    } else {
        echo "Terjadi kesalahan: " . mysqli_error($koneksi);
    }

    // menutup koneksi
    mysqli_close($koneksi);

    // redirect kembalil ke halaman index.php
    header("Location: index.php");
    exit();
} else {
    echo "ID anggota tidak ditemukan.";
}