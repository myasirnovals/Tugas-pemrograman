<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Tambah Kategori Buku</title>
</head>
<body>
<h2>Tambah Kategori Buku Baru</h2>

<form action="" method="post">
    <label for="nama_kategori">Nama Kategori Buku:</label><br>
    <input type="text" name="nama_kategori" id="nama_kategori" required><br><br>

    <input type="submit" value="Tambah Kategori Buku" name="submit">
</form>
<?php
if (isset($_POST['submit'])) {
    // koneksi ke database
    include '../../config/koneksi.php';

    // mengambil data dari form
    $nama_kategori = $_POST['nama_kategori'];

    // query untuk menambahkan data kategori
    $sql = "INSERT INTO kategori_buku (nama_kategori) VALUES ('$nama_kategori')";

    // menjalankan query
    if (mysqli_query($koneksi, $sql)) { ?>
        <p>Data kategori berhasil ditambahkan!</p>
        <br><a href="index.php">Kembali ke daftar kategori</a>
    <?php } else { ?>
        <p>Terjadi kesalahan: <?php mysqli_error($koneksi); ?></p>
    <?php }
    // menutup koneksi
    mysqli_close($koneksi);
    ?>
<?php } ?>
</body>
</html>