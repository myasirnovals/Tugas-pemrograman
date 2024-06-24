<?php
require_once __DIR__ . "/functions.php";

$id = $_GET['id'];

$students = getData("SELECT * FROM mahasiswa WHERE id = '$id'");
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Detail Siswa</title>

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="../../css/bootstrap.min.css">
</head>
<body>
<div class="container-fluid">
    <div class="container mt-5 mb-5">
        <h3 class="mt-5 mb-5">Detail Siswa</h3>
        <div class="card border-4 w-50 ">
            <ul class="list-group">
                <li class="list-group-item">
                    <img src="../../image/<?= $students['gambar']; ?>"
                         alt="gambar"
                         class="img-thumbnail w-50">
                </li>
                <li class="list-group-item">NIM: <?= $students['nim']; ?></li>
                <li class="list-group-item">Nama: <?= $students['nama']; ?></li>
                <li class="list-group-item">Email: <?= $students['email']; ?></li>
                <li class="list-group-item">Klub: <?= $students['club']; ?></li>
                <li class="list-group-item">
                    <a href="#" class="btn btn-primary">Ubah</a>
                    &nbsp;
                    <a href="#" class="btn btn-danger">Hapus</a>
                </li>
                <li class="list-group-item">
                    <a href="latihan3.php" class="btn btn-outline-warning w-100">Kembali ke daftar mahasiswa</a>
                </li>
            </ul>
        </div>
    </div>
</div>

<!-- Bootstrap JS -->
<script src="../../js/bootstrap.min.js"></script>
</body>
</html>