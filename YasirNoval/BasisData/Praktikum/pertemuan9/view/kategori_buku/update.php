<?php
// koneksi ke database
include '../../config/koneksi.php';

// cek apakah data ID yang dikirimkan melalui URL
if (isset($_GET['id'])) {
    $kategori_id = $_GET['id'];

    // query untuk mendapatkan data kategori berdasarkan ID
    $sql = "SELECT * FROM kategori_buku WHERE kategori_id = '$kategori_id'";
    $result = mysqli_query($koneksi, $sql);

    // jika data ditemukan, tampilkan di form
    if (mysqli_num_rows($result) == 1) {
        $row = mysqli_fetch_assoc($result);
        $nama_kategori = $row['nama_kategori'];
    } else {
        echo "Data tidak ditemukan.";
        exit();
    }
} else {
    echo "Data tidak ditemukan.";
    exit();
}

// proses update data ketika form disubmit
if (isset($_POST['submit'])) {
    $nama_kategori = $_POST['nama_kategori'];

    // query update data kategori
    $sql_update = "UPDATE kategori_buku SET nama_kategori = '$nama_kategori' WHERE kategori_id = '$kategori_id'";

    if (mysqli_query($koneksi, $sql_update)) { ?>
        <p>Data kategori berhasil diperbarui!</p>
        <a href="index.php">Kembali ke daftar kategori</a>
    <?php } else { ?>
        <p>Terjadi kesalahan: <?php mysqli_error($koneksi); ?></p>
    <?php }
    // menutup koneksi
    mysqli_close($koneksi);
    ?>
<?php } ?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Update kategori</title>
</head>
<body>
<h2>Update Kategori</h2>
<form action="" method="post">
    <label for="nama_kategori">Nama Kategori: </label><br>
    <input type="text" name="nama_kategori" id="nama_kategori" value="<?= $nama_kategori ?>" required><br><br>
    <input type="submit" value="Update Kategori" name="submit">
</form>
</body>
</html>
