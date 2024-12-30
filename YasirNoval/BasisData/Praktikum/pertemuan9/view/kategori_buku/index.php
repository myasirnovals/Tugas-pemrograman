<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Data Kategori Buku Dengan Filter</title>
</head>
<body>
<h2>Data Kategori Buku</h2>

<a href="tambah.php">
    <button>Tambah Kategori Buku</button>
</a>
<br><br>
<?php
// koneksi ke database
include '../../config/koneksi.php';

// mengambil nilai filter dari form
$filter = isset($_GET['filter']) ? $_GET['filter'] : '';

// query untuk menampilkan data kategori
$sql = "SELECT * FROM kategori_buku";

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
            <th>ID Kategori Buku</th>
            <th>Nama Kategori Buku</th>
            <th>Action</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['kategori_id'] ?></td>
                <td><?= $row['nama_kategori'] ?></td>
                <td>
                    <a href="update.php?id=<?= $row['kategori_id'] ?>">Update</a> |
                    <a href="delete.php?id=<?= $row['kategori_id'] ?>"
                       onclick="return confirm('Apakah anda yakin ingin menghapus kategori ini?')">Hapus</a>
                </td>
            </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Tidak ada data kategori yang ditemukan.</p>
<?php } ?>
<?php
// menutup koneksi
mysqli_close($koneksi);
?>
<br>
</body>
</html>