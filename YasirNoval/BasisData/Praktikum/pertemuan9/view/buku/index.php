<?php
// koneksi ke database
include '../../config/koneksi.php';

// mengambil nilai filter dari form
$filter = isset($_GET['filter']) ? $_GET['filter'] : '';

// query untuk menampilkan data buku
$sql_buku = "SELECT buku.buku_id, buku.judul_buku, buku.pengarang, buku.tahun_terbit, kategori_buku.nama_kategori as kategori FROM buku INNER JOIN kategori_buku WHERE buku.kategori_id = kategori_buku.kategori_id";
$sql_kategori = "SELECT * FROM kategori_buku";

// menambahkan filter jenis kelamin jika ada
if ($filter != '') {
    $sql_buku .= " AND buku.kategori_id = '$filter'";
}

// menjalankan query
$result = mysqli_query($koneksi, $sql_buku);
$result_kategori = mysqli_query($koneksi, $sql_kategori); ?>
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
    Filter Kategori Buku:
    <select name="filter" id="">
        <option value="" selected>Semua</option>
        <?php while ($row = mysqli_fetch_assoc($result_kategori)) { ?>
            <option value="<?= $row['kategori_id'] ?>" <?php if (isset($_GET['filter']) && $_GET['filter'] == $row['kategori_id']) echo 'selected'; ?> >
                <?= $row['nama_kategori'] ?>
            </option>
        <?php } ?>
    </select>
    <input type="submit" value="Terapkan Filter">
</form>
<!-- Tombol tambah buku -->
<a href="tambah.php">
    <button>Tambah Buku</button>
</a>
<br><br>
<?php if (mysqli_num_rows($result) > 0) { ?>
    <table border="1">
        <tr>
            <th>ID Buku</th>
            <th>Judul Buku</th>
            <th>Pengarang</th>
            <th>Tahun Terbit</th>
            <th>Kategori Buku</th>
            <th>Action</th>
        </tr>
        <?php while ($row = mysqli_fetch_assoc($result)) { ?>
            <tr>
                <td><?= $row['buku_id'] ?></td>
                <td><?= $row['judul_buku'] ?></td>
                <td><?= $row['pengarang'] ?></td>
                <td><?= $row['tahun_terbit'] ?></td>
                <td><?= $row['kategori'] ?></td>
                <td>
                    <a href="update.php?id=<?= $row['buku_id'] ?>">Update</a> |
                    <a href="delete.php?id=<?= $row['buku_id'] ?>"
                       onclick="return confirm('Apakah anda yakin ingin menghapus buku ini?')">Hapus</a>
                </td>
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
<br>
</body>
</html>