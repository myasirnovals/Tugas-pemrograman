<?php
// koneksi ke database
include '../../config/koneksi.php';

$sql_kategori = "SELECT * FROM kategori_buku";
$result_kategori = mysqli_query($koneksi, $sql_kategori);

// cek apakah data ID yang dikirimkan melalui URL
if (isset($_GET['id'])) {
    $buku_id = $_GET['id'];

    // query untuk mendapatkan data buku berdasarkan ID
    $sql = "SELECT * FROM buku WHERE buku_id = '$buku_id'";
    $result = mysqli_query($koneksi, $sql);

    // jika data ditemukan, tampilkan di form
    if (mysqli_num_rows($result) == 1) {
        $row = mysqli_fetch_assoc($result);
        $judul_buku = $row['judul_buku'];
        $pengarang = $row['pengarang'];
        $tahun_terbit = $row['tahun_terbit'];
        $kategori_id = $row['kategori_id'];
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
    $judul_buku = $_POST['judul_buku'];
    $pengarang = $_POST['pengarang'];
    $tahun_terbit = $_POST['tahun_terbit'];
    $kategori_id = $_POST['kategori_id'];

    // query update data buku
    $sql_update = "UPDATE buku SET 
                   judul_buku = '$judul_buku',
                   pengarang = '$pengarang',
                   tahun_terbit = '$tahun_terbit$',
                   kategori_id = '$kategori_id'
                   WHERE buku_id = '$buku_id'";

    if (mysqli_query($koneksi, $sql_update)) { ?>
        <p>Data buku berhasil diperbarui!</p>
        <a href="index.php">Kembali ke daftar buku</a>
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
    <title>Update buku</title>
</head>
<body>
<h2>Update Buku</h2>
<form action="" method="post">
    <label for="judul_buku">Nama Buku: </label><br>
    <input type="text" name="judul_buku" id="judul_buku" value="<?= $judul_buku ?>" required><br><br>

    <label for="pengarang">Pengarang: </label><br>
    <input type="text" name="pengarang" id="pengarang" value="<?= $pengarang ?>" required><br><br>

    <label for="kategori_id">Kategori Buku:</label>
    <select name="kategori_id" id="kategori_id">
        <?php while ($row = mysqli_fetch_assoc($result_kategori)) { ?>
            <option value="<?= $row['kategori_id'] ?>" <?php if ($kategori_id == $row['kategori_id']) echo 'selected'; ?>><?= $row['nama_kategori'] ?></option>
        <?php } ?>
    </select><br><br>

    <label for="tahun_terbit">Tahun Terbit: </label>
    <input type="date" name="tahun_terbit" id="tahun_terbit" value="<?= $tahun_terbit ?>" required><br><br>

    <input type="submit" value="Update Buku" name="submit">
</form>
</body>
</html>
