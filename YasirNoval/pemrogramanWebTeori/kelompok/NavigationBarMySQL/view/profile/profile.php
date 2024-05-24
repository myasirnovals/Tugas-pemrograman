<?php include "header.php"; ?>

    <div class="container mt-5">
        <?php foreach ($result as $data) { ?>
            <?php if ($data["nim"] == $_GET["nim"]) { ?>
                <h2><?= $data["nama"]; ?></h2>
                <div class="card mt-3 shadow">
                    <div class="card-body">
                        <h3>Data Diri</h3>
                        <hr>
                        <div class="row">
                            <div class="col-6">
                                <h5>NIM: <?= $data["nim"]; ?></h5>
                                <h5>Kelas: <?= $data["kelas"]; ?></h5>
                                <h5>Angkatan :<?= $data["angkatan"]; ?></h5>
                                <br>
                                <p><?= $data["deskripsi"]; ?></p>
                            </div>
                            <div class="col-6">
                                <?php if ($data['image'] === "-") { ?>
                                    <img class="img-thumbnail" src="../../assets/img/user_icon_150670.png" alt="user" width="250">
                                <?php } else { ?>
                                    <img class="img-thumbnail" src="../../assets/img/<?= $data['image']; ?>"
                                         alt="gambar <?= $data['nama']; ?>"
                                         width="250">
                                <?php } ?>
                            </div>
                        </div>
                    </div>
                </div>
            <?php } ?>
        <?php } ?>
    </div>

<?php include "footer.php" ?>