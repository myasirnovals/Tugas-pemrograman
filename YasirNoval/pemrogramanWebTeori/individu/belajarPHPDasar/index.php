<?php

require_once 'functions.php';

$mahasiswa = query("SELECT * FROM mahasiswa");

// tombol cari ditekan
if (isset($_POST['cari'])) {
    $mahasiswa = cari($_POST['keyword']);
}

?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Halaman Admin</title>
</head>
<body>
<h1>Daftar Mahasiswa</h1>
<a href="tambah.php">Tambah data mahasiswa</a>
<br><br>
<form action="" method="post">
    <input type="text" name="keyword" size="40" autofocus placeholder="Masukan keyword pencarian" autocomplete="off">
    <button type="submit" name="cari">Cari!</button>
    <br><br>
</form>
<table border="1" cellpadding="10" cellspacing="0">
    <thead>
    <tr>
        <th>No</th>
        <th>Aksi</th>
        <th>Gambar</th>
        <th>NRP</th>
        <th>Nama</th>
        <th>Email</th>
        <th>Jurusan</th>
    </tr>
    </thead>
    <tbody>
    <?php $no = 1; ?>
    <?php foreach ($mahasiswa as $mhs) {?>
        <tr>
            <td><?= $no;?></td>
            <td>
                <a href="ubah.php?id=<?= $mhs['id']; ?>">Ubah</a> |
                <a href="hapus.php?id=<?= $mhs['id']; ?>" onclick="return confirm('Yakin?')">Hapus</a>
            </td>
            <td>
                <img src="img/<?= $mhs['gambar']; ?>" width="75">
            </td>
            <td><?= $mhs['nrp']; ?></td>
            <td><?= $mhs['nama']; ?></td>
            <td><?= $mhs['email']; ?></td>
            <td><?= $mhs['jurusan']; ?></td>
        </tr>
        <?php $no++; ?>
    <?php } ?>
    </tbody>
</table>
</body>
</html>
