<?php

include "../services/Functions.php";
include "header.php";

$id = $_GET['id'];

$sql = queryData("SELECT * FROM data_formulir WHERE nim = '$id'");

?>
<div class="container">
    <div class="row">
        <div class="row text-center my-5">
            <div class="col">
                <?php if (isset($sql) && $sql->nim == $id) { ?>
                    <h2>Halo nama saya <?= $sql->nama; ?></h2>
                <?php } else { ?>
                    <h2>Halo nama saya Nama</h2>
                <?php } ?>
            </div>
        </div>
        <div class="col-5">
            <!-- card -->
            <section id="main" class="mb-5">
                <div class="container">
                    <div class="row justify-content-evenly">
                        <div class="col-3" style="width: 18rem">
                            <div class="card shadow">
                                <?php if ($sql->nim == "2350081010") { ?>
                                    <img src="../image/aryawallpaper.jpg" class="img-fluid rounded-2" alt="Arya"/>
                                <?php } elseif ($sql->nim == "2350081004") { ?>
                                    <img src="../image/user_icon_150670.png" class="img-fluid rounded-2" alt="Yasir"/>
                                <?php } elseif ($sql->nim == "2350081005") { ?>
                                    <img src="../image/syivana.jpg" class="img-fluid rounded-2" alt="Syivana"/>
                                    <?php
                                } else {
                                    echo "<script>alert('Data tidak ditemukan 404 not found')</script>";
                                    exit();
                                } ?>
                                <div class="card-body text-center">
                                    <?php if (isset($sql) && $sql->nim == $id) { ?>
                                        <h5 class="card-title"><?= $sql->nama; ?></h5>
                                    <?php } else { ?>
                                        <h5 class="card-title">Nama</h5>
                                    <?php } ?>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </section>
            <!-- end card -->
        </div>
        <div class="col-7">
            <div class="container">
                <div class="row justify-content-evenly">
                    <div class="col-12">
                        <div class="card shadow">

                            <div class="card-body">
                                <h5>Informasi</h5>
                                <h6 class="card-title">Nama : <?= $sql->nama; ?></h6>
                                <h6 class="card-title">NIM : <?= $sql->nim; ?></h6>
                                <h6 class="card-title">Alamat : <?= $sql->alamat; ?></h6>
                                <h6 class="card-title">Hobi : <?= $sql->hobby; ?></h6>
                                <br>
                                <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Accusamus atque blanditiis
                                    corporis culpa deserunt dignissimos dolore ducimus facilis illum incidunt iste
                                    maxime natus, omnis possimus quibusdam repellendus repudiandae sint veritatis.</p>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
<?php include "footer.php"; ?>
