<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Data Peminjaman Dengan Filter</title>
</head>
<body>
<h2>Data Peminjaman</h2>

<form action="index.php" method="get">
    <label for="filter">Filter Tanggal Peminjaman:</label>
    <input type="date" name="filter" id="filter">
    <input type="submit" value="Terapkan Filter">
</form>
<!-- Tombol tambah peminjaman -->
<a href="tambah.php">
    <button>Tambah Peminjaman</button>
</a>
<br><br>
<?php
// koneksi ke database
include '../../config/koneksi.php';

// mengambil nilai filter dari form
$filter = isset($_GET['filter']) ? $_GET['filter'] : '';

// query untuk menampilkan data peminjaman
$sql = "SELECT * FROM peminjaman";

// menambahkan filter jenis kelamin jika ada
if ($filter != '') {
    $sql .= " WHERE tanggal_peminjaman = '$filter'";
}

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
            <th>Action</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['peminjaman_id'] ?></td>
                <td><?= $row['anggota_id'] ?></td>
                <td><?= $row['buku_id'] ?></td>
                <td><?= $row['petugas_id'] ?></td>
                <td><?= $row['tanggal_peminjaman'] ?></td>
                <td><?= $row['tanggal_pengembalian'] ?></td>
                <td>
                    <a href="update.php?id=<?= $row['peminjaman_id'] ?>">Update</a> |
                    <a href="delete.php?id=<?= $row['peminjaman_id'] ?>"
                       onclick="return confirm('Apakah anda yakin ingin menghapus peminjaman ini?')">Hapus</a>
                </td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data peminjaman yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
<br>
</body>
</html>