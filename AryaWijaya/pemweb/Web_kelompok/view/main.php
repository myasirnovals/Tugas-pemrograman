<?php

include "../services/Functions.php";
include "header.php";

if (isset($_POST['submit'])) {
    if (addData($_POST) > 0) {
        echo "<script>alert('Data berhasil ditambahkan!'); document.location.href = 'main.php';</script>";
    } else {
        echo "<script>alert('Data gagal ditambahkan!');</script>";
    }
}


?>
    <!-- card -->
    <section id="main" class="mb-5">
        <div class="container">
            <div class="row text-center my-5">
                <div class="col">
                    <h2>Selamat Datang di Website Kami</h2>
                </div>
            </div>
            <?php
            $sqlA = queryData("SELECT * FROM data_formulir WHERE nim = '2350081010'");
            $sqlY = queryData("SELECT * FROM data_formulir WHERE nim = '2350081004'");
            $sqlS = queryData("SELECT * FROM data_formulir WHERE nim = '2350081005'");
            /**
             * query ke db select * from 
             * 
             * simpen hasil queryna di variable
             * 
             * terus di looping si variablenya
             * 
             * jadi nanti gk harus nulis 1 per 1 
             * 
             * 
             */
            ?>
            <div class="row justify-content-evenly">
                <div class="col-3" style="width: 18rem">
                    <div class="card shadow">
                        <img src="../image/aryawallpaper.jpg" class="img-fluid rounded-2" alt="<?= $sqlA->nama; ?>"/>
                        <div class="card-body text-center">
                            <?php if (isset($sqlA) && $sqlA->nim == "2350081010") { ?>
                                <h5 class="card-title"><?= $sqlA->nama; ?></h5>
                            <?php } else { ?>
                                <h5 class="card-title">Nama</h5>
                            <?php } ?>
                            <p class="card-text">Lorem Ipsum</p>
                            <a href="detailInfo.php?id=2350081010" class="btn btn-info">Lihat Selengkapnya</a>
                        </div>
                    </div>
                </div>
                <div class="col-3" style="width: 18rem">
                    <div class="card shadow">
                        <img src="../image/user_icon_150670.png" class="img-fluid rounded-2" alt="<?= $sqlY->nama; ?>"/>
                        <div class="card-body text-center">
                            <?php if (isset($sqlY) && $sqlY->nim == "2350081004") { ?>
                                <h5 class="card-title"><?= $sqlY->nama; ?></h5>
                            <?php } else { ?>
                                <h5 class="card-title">Nama</h5>
                            <?php } ?>
                            <p class="card-text">Lorem Ipsum</p>
                            <a href="detailInfo.php?id=2350081004" class="btn btn-info">Lihat Selengkapnya</a>
                        </div>
                    </div>
                </div>
                <div class="col-3" style="width: 18rem">
                    <div class="card shadow">
                        <img src="../image/syivana.jpg" class="img-fluid rounded-2" alt="<?= $sqlS->nama; ?>"/>
                        <div class="card-body text-center">
                            <?php if (isset($sqlS) && $sqlS->nim == "2350081005") { ?>
                                <h5 class="card-title"><?= $sqlS->nama; ?></h5>
                            <?php } else { ?>
                                <h5 class="card-title">Nama</h5>
                            <?php } ?>
                            <p class="card-text">Lorem Ipsum</p>
                            <a href="detailInfo.php?id=2350081005" class="btn btn-info">Lihat Selengkapnya</a>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>
    <!-- end card -->
    <!-- form -->
    <section id="form" class="mb-5">
        <div class="container">
            <div class="row text-center">
                <div class="col">
                    <h3>Form</h3>
                </div>
            </div>
            <div class="row justify-content-center">
                <div class="col-4">
                    <form method="post" id="form" class="form">
                        <div class="mb-3">
                            <label for="name" class="form-label">Nama Lengkap</label>
                            <input type="text" class="form-control" name="name" id="name" aria-describedby="name"
                                   required>
                        </div>
                        <div class="mb-3">
                            <label for="nim" class="form-label">NIM</label>
                            <input type="text" class="form-control" name="nim" id="nim" aria-describedby="nim" required>
                        </div>
                        <div class="mb-3">
                            <label for="address" class="form-label">Alamat</label>
                            <textarea name="address" id="address" cols="30" rows="4" class="form-control"
                                      placeholder="Alamat anda" required></textarea>
                        </div>
                        <div class="mb-3">
                            <label for="hobby" class="form-label">Hobi</label>
                            <input type="text" class="form-control" name="hobby" id="hobby" aria-describedby="hobby"
                                   required>
                            <div id="" class="form-text">Pisahkan dengan tanda koma (,) untuk hobi lebih dari 1</div>
                        </div>
                        <br>
                        <button type="submit" name="submit" class="btn btn-primary">Submit</button>
                    </form>
                </div>
            </div>
        </div>
    </section>
    <!-- end form -->
<?php include "footer.php"; ?>