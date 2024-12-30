<?php
// koneksi ke database
include '../../config/koneksi.php';

$sql_kategori = "SELECT * FROM kategori_buku";
$result_kategori = mysqli_query($koneksi, $sql_kategori);
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Tambah Buku</title>
</head>
<body>
<h2>Tambah Buku Baru</h2>

<form action="" method="post">
    <label for="judul_buku">Nama Buku:</label><br>
    <input type="text" name="judul_buku" id="judul_buku" required><br><br>

    <label for="pengarang">Pengarang:</label><br>
    <input type="text" name="pengarang" id="pengarang">
    <br><br>

    <label for="kategori_id">Kategori Buku:</label>
    <select name="kategori_id" id="kategori_id">
        <?php while ($row = mysqli_fetch_assoc($result_kategori)) { ?>
            <option value="<?= $row['kategori_id'] ?>"><?= $row['nama_kategori'] ?></option>
        <?php } ?>
    </select><br><br>

    <label for="tahun_terbit">Tahun Terbit: </label>
    <input type="date" name="tahun_terbit" id="tahun_terbit" required><br><br>

    <input type="submit" value="Tambah Buku" name="submit">
</form>
<?php
if (isset($_POST['submit'])) {
    // mengambil data dari form
    $judul_buku = $_POST['judul_buku'];
    $pengarang = $_POST['pengarang'];
    $tahun_terbit = $_POST['tahun_terbit'];
    $kategori_id = $_POST['kategori_id'];

    // query untuk menambahkan data buku
    $sql = "INSERT INTO buku (judul_buku, pengarang, tahun_terbit, kategori_id) VALUES ('$judul_buku', '$pengarang', '$tahun_terbit', '$kategori_id')";

    // menjalankan query
    if (mysqli_query($koneksi, $sql)) { ?>
        <p>Data buku berhasil ditambahkan!</p>
        <br><a href="index.php">Kembali ke daftar buku</a>
    <?php } else { ?>
        <p>Terjadi kesalahan: <?php mysqli_error($koneksi); ?></p>
    <?php }
    // menutup koneksi
    mysqli_close($koneksi);
    ?>
<?php } ?>
</body>
</html>