<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Kategori Buku</title>
</head>
<body>
<h2>Data Kategori Buku</h2>
<?php
// Koneksi ke database
include 'koneksi.php';

// query join untuk menampilkan data buku beserta nama kategorinya
$sql = "SELECT * FROM kategori_buku";

// menjalankan query
$result = mysqli_query($koneksi, $sql);

// cek apakah ada data yang ditemukan
if (mysqli_num_rows($result) > 0) { ?>
    <table border="1">
        <tr>
            <th>Kategori ID</th>
            <th>Nama Kategori</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['kategori_id'] ?></td>
                <td><?= $row['nama_kategori'] ?></td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data kategori buku yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
</body>
</html>