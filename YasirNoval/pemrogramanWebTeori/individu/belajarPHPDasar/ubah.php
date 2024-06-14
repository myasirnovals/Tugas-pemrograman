<?php

require_once 'functions.php';

// ambil data dari url
$id = $_GET['id'];

// query data mahasiswa berdasarkan variable id
$mhs = query("SELECT * FROM mahasiswa WHERE id = $id")[0];

// cek apakah tombol submit sudah ditekan atau belum
if (isset($_POST['submit'])) {
    // cek apakah data berhasil diubah atau tidak
    if (ubah($_POST) > 0) {
        echo "<script>alert('Data berhasil diubah!'); document.location.href = 'index.php';</script>";
    } else {
        echo "<script>alert('Data gagal diubah!');</script>";
    }
}

?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Ubah data mahasiswa</title>
</head>
<body>
<h1>Ubah data mahasiswa</h1>
<form action="" method="post" enctype="multipart/form-data">
    <input type="hidden" name="id" value="<?= $mhs['id']; ?>">
    <input type="hidden" name="gambarLama" value="<?= $mhs['gambar']; ?>">
    <table>
        <tr>
            <td><label>Nama</label></td>
            <td>:</td>
            <td><input type="text" name="nama" value="<?= $mhs['nama']; ?>" required></td>
        </tr>
        <tr>
            <td><label>NRP</label></td>
            <td>:</td>
            <td><input type="text" name="nrp" value="<?= $mhs['nrp']; ?>" required></td>
        </tr>
        <tr>
            <td><label>Email</label></td>
            <td>:</td>
            <td><input type="text" name="email" value="<?= $mhs['email']; ?>" required></td>
        </tr>
        <tr>
            <td><label>Jurusan</label></td>
            <td>:</td>
            <td><input type="text" name="jurusan" value="<?= $mhs['jurusan']; ?>" required></td>
        </tr>
        <tr>
            <td><label>Gambar/Foto</label></td>
            <td>:</td>
            <td><br><img src="img/<?= $mhs['gambar']; ?>" width="75"><br><br><input type="file" name="gambar"></td>
        </tr>
        <tr>
            <td>
                <button type="submit" name="submit">Ubah Data!</button>
            </td>
        </tr>
    </table>
</form>
</body>
</html>