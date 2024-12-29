<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Petugas</title>
</head>
<body>
<h2>Data Petugas</h2>
<?php
// Koneksi ke database
include 'koneksi.php';

// query join untuk menampilkan data buku beserta nama kategorinya
$sql = "SELECT * FROM petugas";

// menjalankan query
$result = mysqli_query($koneksi, $sql);

// cek apakah ada data yang ditemukan
if (mysqli_num_rows($result) > 0) { ?>
    <table border="1">
        <tr>
            <th>ID Petugas</th>
            <th>Nama Petugas</th>
            <th>Jenis Kelamin</th>
            <th>No HP</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['petugas_id'] ?></td>
                <td><?= $row['nama_petugas'] ?></td>
                <td><?= $row['jenis_kelamin'] ?></td>
                <td><?= $row['no_hp'] ?></td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data Petugas yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
</body>
</html>