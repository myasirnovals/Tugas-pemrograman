<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Total Denda</title>
</head>
<body>
<h2>Data Total Denda</h2>
<?php
// Koneksi ke database
include 'koneksi.php';

// query join untuk menampilkan data buku beserta nama kategorinya
$sql = "SELECT SUM(jumlah_denda) as total_denda FROM denda";

// menjalankan query
$result = mysqli_query($koneksi, $sql);

// cek apakah ada data yang ditemukan
if (mysqli_num_rows($result) > 0) { ?>
    <table border="1">
        <tr>
            <th>Jumlah Denda</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td>Rp. <?= $row['total_denda'] ?>, 00</td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data Denda yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
</body>
</html>