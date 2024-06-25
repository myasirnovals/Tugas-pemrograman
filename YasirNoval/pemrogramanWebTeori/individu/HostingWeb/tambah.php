<?php
session_start();

if (!isset($_SESSION['login'])) {
    header("Location: login.php");
    exit();
}

require_once __DIR__ . "/functions.php";

// cek apakah tombol tambah sudah ditekan
if (isset($_POST['tambah'])) {
    if (tambah($_POST) > 0) {
        echo "<script>alert('Data berhasil ditambahkan'); document.location.href = 'index.php';</script>";
    } else {
        echo "Data gagal ditambahkan!";
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
    <title>Tambah Data mahasiswa</title>

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="css/bootstrap.min.css">
</head>
<body>
<div class="container-fluid">
    <div class="container mt-5 mb-5">
        <h3>Tambah Siswa</h3>
        <form action="" method="post" enctype="multipart/form-data">
            <div class="card border-3 w-auto">
                <div class="card-body">
                    <div class="form-group">
                        <label for="nama" class="form-label">Nama: </label>
                        <input type="text" name="nama" id="nama" class="form-control" autofocus required>
                    </div>
                    <div class="form-group">
                        <label for="nim" class="form-label">NIM: </label>
                        <input type="text" name="nim" id="nim" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <label for="email" class="form-label">Email: </label>
                        <input type="text" name="email" id="email" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <label for="club" class="form-label">Klub: </label>
                        <input type="text" name="club" id="club" class="form-control">
                    </div>
                    <hr>
                    <div class="row">
                        <div class="col-md-6 col-sm-12">
                            <div class="form-group">
                                <label for="gambar" class="form-label">Foto: </label>
                                <input type="file" name="gambar" id="gambar" class="form-control w-100 gambar"
                                       onchange="previewImage()">
                            </div>
                            <div class="form-group">
                                <button type="submit" name="tambah" class="btn btn-outline-warning w-100 mt-5">Tambah
                                </button>
                            </div>
                        </div>
                        <div class="col-md-6 col-sm-12 text-center">
                            <div class="form-group">
                                <img src="img/schale.jpg" alt="no photo" class="img-thumbnail w-50 img-preview">
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </form>
        <br><br>
        <a href="index.php">Kembali ke halaman utama</a>
    </div>
</div>

<!-- Bootstrap JS -->
<script src="js/bootstrap.min.js"></script>

<!-- Native JS -->
<script src="js/script.js"></script>
</body>
</html>