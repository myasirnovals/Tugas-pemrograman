<?php
// koneksi ke database
include '../../config/koneksi.php';

// cek apakah data ID yang dikirimkan melalui URL
if (isset($_GET['id'])) {
    $anggota_id = $_GET['id'];

    // query untuk mendapatkan data anggota berdasarkan ID
    $sql = "SELECT * FROM anggota WHERE anggota_id = '$anggota_id'";
    $result = mysqli_query($koneksi, $sql);

    // jika data ditemukan, tampilkan di form
    if (mysqli_num_rows($result) == 1) {
        $row = mysqli_fetch_assoc($result);
        $nama_anggota = $row['nama_anggota'];
        $alamat = $row['alamat'];
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
    $nama_anggota = $_POST['nama_anggota'];
    $alamat = $_POST['alamat'];
    $jenis_kelamin = $_POST['jenis_kelamin'];
    $no_hp = $_POST['no_hp'];

    // query update data anggota
    $sql_update = "UPDATE anggota SET 
                   nama_anggota = '$nama_anggota',
                   alamat = '$alamat',
                   jenis_kelamin = '$jenis_kelamin$',
                   no_hp = '$no_hp'
                   WHERE anggota_id = '$anggota_id'";

    if (mysqli_query($koneksi, $sql_update)) { ?>
        <p>Data anggota berhasil diperbarui!</p>
        <a href="index.php">Kembali ke daftar anggota</a>
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
    <title>Update anggota</title>
</head>
<body>
<h2>Update Anggota</h2>
<form action="" method="post">
    <label for="nama_anggota">Nama Anggota: </label><br>
    <input type="text" name="nama_anggota" id="nama_anggota" value="<?= $nama_anggota ?>" required><br><br>

    <label for="alamat">Alamat: </label><br>
    <textarea name="alamat" id="alamat" cols="30" rows="10" required><?= $alamat ?></textarea><br><br>

    <label for="jenis_kelamin">Jenis Kelamin: </label><br>
    <select name="jenis_kelamin" id="jenis_kelamin">
        <option value="L" <?php if ($jenis_kelamin == 'L') echo 'selected'; ?>>Laki-laki</option>
        <option value="P" <?php if ($jenis_kelamin == 'P') echo 'selected'; ?>>Perempuan</option>
    </select><br><br>

    <label for="no_hp">No Telepon: </label>
    <input type="text" name="no_hp" id="no_hp" value="<?= $no_hp ?>" required><br><br>

    <input type="submit" value="Update Anggota" name="submit">
</form>
</body>
</html>
