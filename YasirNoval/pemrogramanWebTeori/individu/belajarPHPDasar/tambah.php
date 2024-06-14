<?php

require_once 'functions.php';

// cek apakah tombol submit sudah ditekan atau belum
if (isset($_POST['submit'])) {
    // cek apakah data berhasil ditambahkan atau tidak
    if (tambah($_POST) > 0) {
        echo "<script>alert('Data berhasil ditambahkan!'); document.location.href = 'index.php';</script>";
    } else {
        echo "<script>alert('Data gagal ditambahkan!');</script>";
    }
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Tambah data mahasiswa</title>
</head>
<body>
<h1>Tambah data mahasiswa</h1>
<form action="" method="post" enctype="multipart/form-data">
    <table>
        <tr>
            <td><label for="nama">Nama</label></td>
            <td>:</td>
            <td><input type="text" name="nama" id="nama" required></td>
        </tr>
        <tr>
            <td><label for="nrp">NRP</label></td>
            <td>:</td>
            <td><input type="text" name="nrp" id="nrp" required></td>
        </tr>
        <tr>
            <td><label for="email">Email</label></td>
            <td>:</td>
            <td><input type="text" name="email" id="email" required></td>
        </tr>
        <tr>
            <td><label for="jurusan">Jurusan</label></td>
            <td>:</td>
            <td><input type="text" name="jurusan" id="jurusan" required></td>
        </tr>
        <tr>
            <td><label for="gambar">Gambar/Foto</label></td>
            <td>:</td>
            <td><input type="file" name="gambar" id="gambar"></td>
        </tr>
        <tr>
            <td>
                <button type="submit" name="submit">Tambah Data!</button>
            </td>
        </tr>
    </table>
</form>
</body>
</html>