<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Data Petugas Dengan Filter</title>
</head>
<body>
<h2>Data Petugas</h2>

<!-- form untuk filter jenis kelamin -->
<form action="index.php" method="get">
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
<!-- Tombol tambah petugas -->
<a href="tambah.php">
    <button>Tambah Petugas</button>
</a>
<br><br>
<?php
// koneksi ke database
include '../../config/koneksi.php';

// mengambil nilai filter dari form
$filter = isset($_GET['filter']) ? $_GET['filter'] : '';

// query untuk menampilkan data petugas
$sql = "SELECT * FROM petugas";

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
            <th>ID Petugas</th>
            <th>Nama Petugas</th>
            <th>Jenis Kelamin</th>
            <th>No Telepon</th>
            <th>Action</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['petugas_id'] ?></td>
                <td><?= $row['nama_petugas'] ?></td>
                <td><?= $row['jenis_kelamin'] ?></td>
                <td><?= $row['no_hp'] ?></td>
                <td>
                    <a href="update.php?id=<?= $row['petugas_id'] ?>">Update</a> |
                    <a href="delete.php?id=<?= $row['petugas_id'] ?>"
                       onclick="return confirm('Apakah anda yakin ingin menghapus petugas ini?')">Hapus</a>
                </td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data petugas yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
<br>
</body>
</html>