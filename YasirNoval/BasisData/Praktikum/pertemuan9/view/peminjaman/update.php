<?php
// koneksi ke database
include '../../config/koneksi.php';

// cek apakah data ID yang dikirimkan melalui URL
if (isset($_GET['id'])) {
    $peminjaman_id = $_GET['id'];

    // query untuk mendapatkan data peminjaman berdasarkan ID
    $sql = "SELECT peminjaman.*, anggota.nama_anggota, buku.judul_buku, petugas.nama_petugas FROM peminjaman 
            INNER JOIN anggota ON peminjaman.anggota_id = anggota.anggota_id
            INNER JOIN buku ON peminjaman.buku_id = buku.buku_id
            INNER JOIN petugas ON peminjaman.petugas_id = petugas.petugas_id";

    $sql .= " WHERE peminjaman.peminjaman_id = '$peminjaman_id'";
    $result = mysqli_query($koneksi, $sql);

    // jika data ditemukan, tampilkan di form
    if (mysqli_num_rows($result) == 1) {
        $row = mysqli_fetch_assoc($result);
        $anggota_id = $row['anggota_id'];
        $buku_id = $row['buku_id'];
        $petugas_id = $row['petugas_id'];
        $tanggal_peminjaman = $row['tanggal_peminjaman'];
        $tanggal_pengembalian = $row['tanggal_pengembalian'];
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
    $anggota_id = $_POST['anggota_id'];
    $buku_id = $_POST['buku_id'];
    $petugas_id = $_POST['petugas_id'];
    $tanggal_peminjaman = $_POST['tanggal_peminjaman'];
    $tanggal_pengembalian = $_POST['tanggal_pengembalian'];

    // query update data peminjaman
    $sql_update = "UPDATE peminjaman SET 
                   anggota_id = '$anggota_id',
                   buku_id = '$buku_id',
                   petugas_id= '$petugas_id',
                   tanggal_peminjaman = '$tanggal_peminjaman',
                   tanggal_pengembalian = '$tanggal_pengembalian'
                   WHERE peminjaman_id = '$peminjaman_id'";

    if (mysqli_query($koneksi, $sql_update)) { ?>
        <p>Data peminjaman berhasil diperbarui!</p>
        <a href="index.php">Kembali ke daftar peminjaman</a>
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
    <title>Update peminjaman</title>
</head>
<body>
<h2>Update Anggota</h2>
<form action="" method="post">
    <input type="hidden" name="anggota_id" id="anggota_id" value="<?= $anggota_id ?>">
    <input type="hidden" name="buku_id" id="buku_id" value="<?= $buku_id ?>">
    <input type="hidden" name="petugas_id" id="petugas_id" value="<?= $petugas_id ?>">

    <label for="nama_anggota">ID Anggota: </label><br>
    <input type="text" name="nama_anggota" id="nama_anggota" value="<?= $row['nama_anggota']?>" disabled><br><br>


    <label for="judul_buku">ID Buku:</label><br>
    <input type="text" name="judul_buku" id="judul_buku" value="<?= $row['judul_buku']?>" disabled><br><br>

    <label for="nama_petugas">ID Petugas:</label><br>
    <input type="text" name="nama_petugas" id="nama_petugas" value="<?= $row['nama_petugas']?>" disabled><br><br>


    <label for="tanggal_peminjaman">Tanggal Peminjaman: </label>
    <input type="date" name="tanggal_peminjaman" id="tanggal_peminjaman" value="<?= $tanggal_peminjaman ?>"
           required><br><br>

    <label for="tanggal_pengembalian">Tanggal Pengembalian: </label>
    <input type="date" name="tanggal_pengembalian" id="tanggal_pengembalian" value="<?= $tanggal_pengembalian ?>"
           required><br><br>

    <input type="submit" value="Update peminjaman" name="submit">
</form>
</body>
</html>
