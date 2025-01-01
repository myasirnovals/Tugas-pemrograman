<?php
// koneksi ke database
include '../../config/koneksi.php';

// query untuk menampilkan data peminjaman
$sql_anggota = "SELECT * FROM anggota";
$result_anggota = mysqli_query($koneksi, $sql_anggota);

$sql_buku = "SELECT * FROM buku";
$result_buku = mysqli_query($koneksi, $sql_buku);

$sql_petugas = "SELECT * FROM petugas";
$result_petugas = mysqli_query($koneksi, $sql_petugas);
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Tambah Anggota</title>
</head>
<body>
<h2>Tambah Anggota Baru</h2>

<form action="" method="post">
    <label for="anggota_id">Nama Anggota:</label><br>
    <select name="anggota_id" id="anggota_id">
        <?php while ($row = mysqli_fetch_assoc($result_anggota)) { ?>
            <option value="<?= $row['anggota_id'] ?>"><?= $row['nama_anggota'] ?></option>
        <?php } ?>
    </select><br><br>

    <label for="buku_id">Judul Buku:</label><br>
    <select name="buku_id" id="buku_id">
        <?php while ($row = mysqli_fetch_assoc($result_buku)) { ?>
            <option value="<?= $row['buku_id'] ?>"><?= $row['judul_buku'] ?></option>
        <?php } ?>
    </select><br><br>

    <label for="petugas_id">Nama Petugas:</label><br>
    <select name="petugas_id" id="petugas_id">
        <?php while ($row = mysqli_fetch_assoc($result_petugas)) { ?>
            <option value="<?= $row['petugas_id'] ?>"><?= $row['nama_petugas'] ?></option>
        <?php } ?>
    </select><br><br>

    <label for="tanggal_peminjaman">Tanggal Peminjaman:</label>
    <input type="date" name="tanggal_peminjaman" id="tanggal_peminjaman" required><br><br>

    <label for="tanggal_pengembalian">Tanggal Pengembalian:</label>
    <input type="date" name="tanggal_pengembalian" id="tanggal_pengembalian" required><br><br>

    <input type="submit" value="Tambah Anggota" name="submit">
</form>
<?php
if (isset($_POST['submit'])) {
    // mengambil data dari form
    $anggota_id = $_POST['anggota_id'];
    $buku_id = $_POST['buku_id'];
    $petugas_id = $_POST['petugas_id'];
    $tanggal_peminjaman = $_POST['tanggal_peminjaman'];
    $tanggal_pengembalian = $_POST['tanggal_pengembalian'];

    // query untuk menambahkan data peminjaman
    $sql = "INSERT INTO peminjaman (anggota_id, buku_id, petugas_id, tanggal_peminjaman, tanggal_pengembalian)
            VALUES ('$anggota_id', '$buku_id', '$petugas_id', '$tanggal_peminjaman', '$tanggal_pengembalian')";

    // menjalankan query
    if (mysqli_query($koneksi, $sql)) { ?>
        <p>Data peminjaman berhasil ditambahkan!</p>
        <br><a href="index.php">Kembali ke daftar peminjaman</a>
    <?php } else { ?>
        <p>Terjadi kesalahan: <?php mysqli_error($koneksi); ?></p>
    <?php }
    // menutup koneksi
    mysqli_close($koneksi);
    ?>
<?php } ?>
</body>
</html>