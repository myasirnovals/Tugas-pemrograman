<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Data Buku dan Kategori</title>
</head>
<body>
<h2>Data Buku dan Kategori</h2>
<?php
// Koneksi ke database
include 'koneksi.php';

// query join untuk menampilkan data buku beserta nama kategorinya
$sql = "SELECT buku.buku_id, buku.judul_buku, buku.pengarang, buku.tahun_terbit, kategori_buku.nama_kategori FROM buku INNER JOIN kategori_buku ON buku.kategori_id = kategori_buku.kategori_id";

// menjalankan query
$result = mysqli_query($koneksi, $sql);

// cek apakah ada data yang ditemukan
if (mysqli_num_rows($result) > 0) { ?>
    <table border="1">
        <tr>
            <th>ID Buku</th>
            <th>Judul Buku</th>
            <th>Pengarang</th>
            <th>Tahun Terbit</th>
            <th>Kategori</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['buku_id'] ?></td>
                <td><?= $row['judul_buku'] ?></td>
                <td><?= $row['pengarang'] ?></td>
                <td><?= $row['tahun_terbit'] ?></td>
                <td><?= $row['nama_kategori'] ?></td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data buku yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
</body>
</html>