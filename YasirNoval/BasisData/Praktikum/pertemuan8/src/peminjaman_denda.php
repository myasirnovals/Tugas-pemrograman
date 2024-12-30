<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Peminjaman dan Denda</title>
</head>
<body>
<h2>Data Peminjaman dan Denda</h2>
<?php
include 'koneksi.php';

$sql = "SELECT denda.denda_id, peminjaman.anggota_id, peminjaman.petugas_id, peminjaman.tanggal_peminjaman, peminjaman.tanggal_pengembalian, denda.jumlah_denda FROM denda INNER JOIN peminjaman on denda.peminjaman_id = peminjaman.peminjaman_id";

$result = mysqli_query($koneksi, $sql);
?>

<table border="1">
    <tr>
        <th>ID Denda</th>
        <th>ID Anggota</th>
        <th>ID Petugas</th>
        <th>Tanggal Peminjaman</th>
        <th>Tanggal Pengembalian</th>
        <th>Jumlah Denda</th>
    </tr>
    <?php if ($result) { ?>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <th><?= $row['denda_id'] ?></th>
                <th><?= $row['anggota_id'] ?></th>
                <th><?= $row['petugas_id'] ?></th>
                <th><?= $row['tanggal_peminjaman'] ?></th>
                <th><?= $row['tanggal_pengembalian'] ?></th>
                <th><?= $row['jumlah_denda'] ?></th>
            </tr>
        <?php } ?>
    <?php } ?>
</table>
</body>
</html>