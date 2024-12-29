<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Peminjaman</title>
</head>
<body>
<h2>Data Peminjaman</h2>
<?php
// Koneksi ke database
include 'koneksi.php';

// query join untuk menampilkan data buku beserta nama kategorinya
$sql = "SELECT * FROM peminjaman";

// menjalankan query
$result = mysqli_query($koneksi, $sql);

// cek apakah ada data yang ditemukan
if (mysqli_num_rows($result) > 0) { ?>
    <table border="1">
        <tr>
            <th>ID Peminjaman</th>
            <th>ID Anggota</th>
            <th>ID Buku</th>
            <th>ID Petugas</th>
            <th>Tanggal Peminjaman</th>
            <th>Tanggal Pengembalian</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['peminjaman_id'] ?></td>
                <td><?= $row['anggota_id'] ?></td>
                <td><?= $row['buku_id'] ?></td>
                <td><?= $row['petugas_id'] ?></td>
                <td><?= $row['tanggal_peminjaman'] ?></td>
                <td><?= $row['tanggal_pengembalian'] ?></td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data Peminjaman yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
</body>
</html>