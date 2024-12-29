<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Data anggota dengan filter</title>
</head>
<body>
<h2>Data Anggota</h2>
<!-- Form untuk filter jenis kelamin -->
<form action="anggota.php" method="get">
    Filter Jenis Kelamin:
    <select name="filter" id="">
        <option value="">Semua</option>
        <option value="L" <?php if (isset($_GET['filter']) && $_GET['filter'] == 'L') echo 'selected'; ?> >
            Laki-laki
        </option>
        <option value="P" <?php if (isset($_GET['filter']) && $_GET['filter'] == 'P') echo 'selected'; ?> >
            Perempuan
        </option>
    </select>
    <input type="submit" value="Terapkan Filter">
</form>
<br>
<?php
// koneksi ke database
include 'koneksi.php';

// mengambil nilai filter dari form
$filter = isset($_GET['filter']) ? $_GET['filter'] : '';

// query dasar untuk menampilkan semua data anggota
$sql = "SELECT * FROM anggota";

// menambahkan filter jenis kelamin jika ada
if ($filter != '') {
    $sql .= " WHERE jenis_kelamin = '$filter'";
}

// menjalankan query
$result = mysqli_query($koneksi, $sql);

// cek apakah ada data yang ditemukan
if (mysqli_num_rows($result) > 0) { ?>
    <table border="1">
        <tr>
            <th>ID Anggota</th>
            <th>Nama Anggota</th>
            <th>Alamat</th>
            <th>Jenis Kelamin</th>
            <th>No HP</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['anggota_id'] ?></td>
                <td><?= $row['nama_anggota'] ?></td>
                <td><?= $row['alamat'] ?></td>
                <td><?= $row['jenis_kelamin'] ?></td>
                <td><?= $row['no_hp'] ?></td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
</body>
</html>
