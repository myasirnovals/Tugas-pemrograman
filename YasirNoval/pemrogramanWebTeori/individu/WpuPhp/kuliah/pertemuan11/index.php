<?php
require_once __DIR__ . "/functions.php";

$students = getAllData("SELECT * FROM mahasiswa");

// ketika tombol di klik
if (isset($_POST['cari'])) {
    $students = cari($_POST['keyword']);
}
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
        <h3 class="mt-5 mb-3">Daftar Siswa Kivotos</h3>
        <a href="tambah.php">Tambah Data Mahasiswa</a>
        <br><br>
        <form action="" method="post">
            <div class="row justify-content-end">
                <div class="col-md-8 col-sm-6"></div>
                <div class="col-md-4 col-sm-6">
                    <label for="keyword" class="form-label d-block">Cari siswa dari daftar siswa</label>
                    <input type="text" name="keyword" id="keyword" class="form-control w-75 d-inline"
                           placeholder="Masukan Pencarian...." autocomplete="off">
                    &nbsp;
                    &nbsp;
                    <button type="submit" name="cari" class="btn btn-info text-white d-inline">Cari!</button>
                </div>
            </div>
        </form>
        <br>
        <?php
        $no = 1;
        if (!empty($students)) {
            ?>
            <table class="table table-bordered">
                <thead>
                <tr>
                    <th>No</th>
                    <th>Gambar</th>
                    <th>Nama</th>
                    <th>Aksi</th>
                </tr>
                </thead>
                <?php if (!empty($students)) { ?>
                    <tbody>
                    <?php foreach ($students as $student) { ?>
                        <tr>
                            <td><?= $no++; ?></td>
                            <td>
                                <img src="../../image/<?= $student['gambar']; ?>" alt="Gambar"
                                     class="img-thumbnail w-50">
                            </td>
                            <td><?= $student['nama']; ?></td>
                            <td>
                                <a href="detail.php?id=<?= $student['id']; ?>" class="btn btn-outline-success">Lihat
                                    detail</a>
                            </td>
                        </tr>
                    <?php } ?>
                    </tbody>
                <?php } else { ?>
                    <tbody>
                    <tr>
                        <td colspan="4" style="color: red; text-align: center; font-style: italic"><p>Data Siswa Tidak
                                Ditemukan!</p></td>
                    </tr>
                    </tbody>
                <?php } ?>
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