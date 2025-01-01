<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Tambah Petugas</title>
</head>
<body>
<h2>Tambah Petugas Baru</h2>

<form action="" method="post">
    <label for="nama_petugas">Nama Petugas:</label><br>
    <input type="text" name="nama_petugas" id="nama_petugas" required><br><br>
    
    <label for="jenis_kelamin">Jenis Kelamin:</label>
    <select name="jenis_kelamin" id="jenis_kelamin">
        <option value="L">Laki-laki</option>
        <option value="P">Perempuan</option>
    </select><br><br>

    <label for="no_hp">No Telepon:</label>
    <input type="text" name="no_hp" id="no_hp" required><br><br>

    <input type="submit" value="Tambah Petugas" name="submit">
</form>
<?php
if (isset($_POST['submit'])) {
    // koneksi ke database
    include '../../config/koneksi.php';

    // mengambil data dari form
    $nama_petugas = $_POST['nama_petugas'];
    $no_hp = $_POST['no_hp'];
    $jenis_kelamin = $_POST['jenis_kelamin'];

    // query untuk menambahkan data petugas
    $sql = "INSERT INTO petugas (nama_petugas, no_hp, jenis_kelamin) VALUES ('$nama_petugas', '$no_hp', '$jenis_kelamin')";

    // menjalankan query
    if (mysqli_query($koneksi, $sql)) { ?>
        <p>Data petugas berhasil ditambahkan!</p>
        <br><a href="index.php">Kembali ke daftar petugas</a>
    <?php } else { ?>
        <p>Terjadi kesalahan: <?php mysqli_error($koneksi); ?></p>
    <?php }
    // menutup koneksi
    mysqli_close($koneksi);
    ?>
<?php } ?>
</body>
</html>