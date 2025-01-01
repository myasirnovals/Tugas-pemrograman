<?php
// koneksi ke database
include '../../config/koneksi.php';

// cek apakah ID petugas ada di URL
if (isset($_GET['id'])) {
    $petugas_id = $_GET['id'];

    // query untuk menghapus data petugas
    $sql = "DELETE FROM petugas WHERE petugas_id = '$petugas_id'";

    if (mysqli_query($koneksi, $sql)) {
        echo "Data petugas berhasil dihapus!";
    } else {
        echo "Terjadi kesalahan: " . mysqli_error($koneksi);
    }

    // menutup koneksi
    mysqli_close($koneksi);

    // redirect kembalil ke halaman index.php
    header("Location: index.php");
    exit();
} else {
    echo "ID petugas tidak ditemukan.";
}