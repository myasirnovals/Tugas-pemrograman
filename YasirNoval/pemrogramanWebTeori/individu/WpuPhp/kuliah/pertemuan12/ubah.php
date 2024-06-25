<?php
session_start();

if(!isset($_SESSION['login'])) {
    header("Location: login.php");
    exit();
}

require_once __DIR__ . "/functions.php";

// jika tidak ada id di url
if (!isset($_GET['id'])) {
    header("Location: index.php");
    exit();
}

// ambil id dari url
$id = $_GET['id'];

// query data mahasiswa berdasarkan id
$students = getData("SELECT * FROM mahasiswa WHERE id = '$id'");

// cek apakah tombol ubah sudah ditekan
if (isset($_POST['ubah'])) {
    if (ubah($_POST) > 0) {
        echo "<script>alert('Data berhasil diubah'); document.location.href = 'index.php';</script>";
    } else {
        echo "Data gagal diubah!";
    }
}
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Ubah Data mahasiswa</title>

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="../../css/bootstrap.min.css">
</head>
<body>
<div class="container-fluid">
    <div class="container mt-5 mb-5">
        <h3>Ubah Data Siswa</h3>
        <form action="" method="post">
            <input type="hidden" name="id" value="<?= $students['id']; ?>">
            <div class="card border-3 w-50">
                <div class="card-body">
                    <div class="form-group">
                        <label for="nama" class="form-label">Nama: </label>
                        <input type="text"
                               name="nama"
                               id="nama"
                               class="form-control"
                               value="<?= $students['nama']; ?>">
                    </div>
                    <div class="form-group">
                        <label for="nim" class="form-label">NIM: </label>
                        <input type="text"
                               name="nim"
                               id="nim"
                               class="form-control"
                               value="<?= $students['nim']; ?>">
                    </div>
                    <div class="form-group">
                        <label for="email" class="form-label">Email: </label>
                        <input type="text"
                               name="email"
                               id="email"
                               class="form-control"
                               value="<?= $students['email']; ?>">
                    </div>
                    <div class="form-group">
                        <label for="club" class="form-label">Klub: </label>
                        <input type="text"
                               name="club"
                               id="club"
                               class="form-control"
                               value="<?= $students['club']; ?>">
                    </div>
                    <div class="row">
                        <div class="col-md-6 col-sm-12">
                            <div class="form-group">
                                <label for="gambar" class="form-label">Foto: </label>
                                <br>
                                <img src="../../image/<?= $students['gambar']; ?>" alt="gambar"
                                     class="img-thumbnail w-50">
                                <input type="text"
                                       name="gambar"
                                       id="gambar"
                                       class="form-control w-100"
                                       value="<?= $students['gambar']; ?>">
                            </div>
                        </div>
                        <div class="col-md-6 col-sm-12 text-center">
                            <div class="form-group">
                                <br><br><br><br><br><br>
                                <button type="submit" name="ubah" class="btn btn-outline-warning w-75 mt-2">Ubah
                                </button>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </form>
        <br><br>
        <a href="detail.php?id=<?= $id ?>">kembali ke halaman detail</a>
    </div>
</div>

<!-- Bootstrap JS -->
<script src="../../js/bootstrap.min.js"></script>
</body>
</html>