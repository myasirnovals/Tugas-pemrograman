<?php
require_once __DIR__ . "/functions.php";

$students = getAllData("SELECT * FROM mahasiswa");
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Daftar Siswa Kivotos</title>

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="../../css/bootstrap.min.css">
</head>
<body>
<div class="container-fluid">
    <div class="container mt-5 mb-5">
        <h3>Daftar Siswa Kivotos</h3>
        <?php
        $no = 1;
        if (!empty($students)) {
            ?>
            <table class="table table-bordered">
                <thead>
                <tr>
                    <th>No</th>
                    <th>Gambar</th>
                    <th>NIM</th>
                    <th>Nama</th>
                    <th>Email</th>
                    <th>club</th>
                    <th>Aksi</th>
                </tr>
                </thead>
                <tbody>
                <?php foreach ($students as $student) { ?>
                    <tr>
                        <td><?= $no++; ?></td>
                        <td>
                            <img src="../../image/<?= $student['gambar']; ?>" alt="Gambar" class="img-thumbnail w-50">
                        </td>
                        <td><?= $student['nim']; ?></td>
                        <td><?= $student['nama']; ?></td>
                        <td><?= $student['email']; ?></td>
                        <td><?= $student['club']; ?></td>
                        <td>
                            <a href="#" class="btn btn-outline-primary">Ubah</a>
                            <a href="#" class="btn btn-outline-danger">Hapus</a>
                        </td>
                    </tr>
                <?php } ?>
                </tbody>
            </table>
        <?php } else { ?>
            <h1 class="text-center mt-5 mb-5">Data dalam tabel kosong</h1>
        <?php } ?>
    </div>
</div>

<!-- Bootstrap JS -->
<script src="../../js/bootstrap.min.js"></script>
</body>
</html>