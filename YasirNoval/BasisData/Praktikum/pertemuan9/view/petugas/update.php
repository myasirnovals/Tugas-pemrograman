<?php
// koneksi ke database
include '../../config/koneksi.php';

// cek apakah data ID yang dikirimkan melalui URL
if (isset($_GET['id'])) {
    $petugas_id = $_GET['id'];

    // query untuk mendapatkan data petugas berdasarkan ID
    $sql = "SELECT * FROM petugas WHERE petugas_id = '$petugas_id'";
    $result = mysqli_query($koneksi, $sql);

    // jika data ditemukan, tampilkan di form
    if (mysqli_num_rows($result) == 1) {
        $row = mysqli_fetch_assoc($result);
        $nama_petugas = $row['nama_petugas'];
        $jenis_kelamin = $row['jenis_kelamin'];
        $no_hp = $row['no_hp'];
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
    $nama_petugas = $_POST['nama_petugas'];
    $jenis_kelamin = $_POST['jenis_kelamin'];
    $no_hp = $_POST['no_hp'];

    // query update data petugas
    $sql_update = "UPDATE petugas SET 
                   nama_petugas = '$nama_petugas',
                   jenis_kelamin = '$jenis_kelamin$',
                   no_hp = '$no_hp'
                   WHERE petugas_id = '$petugas_id'";

    if (mysqli_query($koneksi, $sql_update)) { ?>
        <p>Data petugas berhasil diperbarui!</p>
        <a href="index.php">Kembali ke daftar petugas</a>
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
    <title>Update petugas</title>
</head>
<body>
<h2>Update Petugas</h2>
<form action="" method="post">
    <label for="nama_petugas">Nama Petugas: </label><br>
    <input type="text" name="nama_petugas" id="nama_petugas" value="<?= $nama_petugas ?>" required><br><br>

    <label for="jenis_kelamin">Jenis Kelamin: </label><br>
    <select name="jenis_kelamin" id="jenis_kelamin">
        <option value="L" <?php if ($jenis_kelamin == 'L') echo 'selected'; ?>>Laki-laki</option>
        <option value="P" <?php if ($jenis_kelamin == 'P') echo 'selected'; ?>>Perempuan</option>
    </select><br><br>

    <label for="no_hp">No Telepon: </label>
    <input type="text" name="no_hp" id="no_hp" value="<?= $no_hp ?>" required><br><br>

    <input type="submit" value="Update Petugas" name="submit">
</form>
</body>
</html>
