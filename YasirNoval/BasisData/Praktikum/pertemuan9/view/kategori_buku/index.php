<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Data Anggota Dengan Filter</title>
</head>
<body>
<h2>Data Anggota</h2>

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
<!-- Tombol tambah anggota -->
<a href="tambah.php">
    <button>Tambah Anggota</button>
</a>
<br><br>
<?php
// koneksi ke database
include '../../config/koneksi.php';

// mengambil nilai filter dari form
$filter = isset($_GET['filter']) ? $_GET['filter'] : '';

// query untuk menampilkan data anggota
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
            <th>No Telepon</th>
            <th>Action</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['anggota_id'] ?></td>
                <td><?= $row['nama_anggota'] ?></td>
                <td><?= $row['alamat'] ?></td>
                <td><?= $row['jenis_kelamin'] ?></td>
                <td><?= $row['no_hp'] ?></td>
                <td>
                    <a href="update.php?id=<?= $row['anggota_id'] ?>">Update</a> |
                    <a href="delete.php?id=<?= $row['anggota_id'] ?>"
                       onclick="return confirm('Apakah anda yakin ingin menghapus anggota ini?')">Hapus</a>
                </td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data anggota yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
<br>
</body>
</html>