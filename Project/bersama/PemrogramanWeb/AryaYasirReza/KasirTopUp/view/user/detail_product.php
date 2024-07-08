<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container mt-5 mb-5">
        <?php $id_game = $_GET['id']; ?>
        <?php if (!empty($dataProducts)) { ?>
            <div class="row">
                <?php foreach ($dataProducts as $data) { ?>
                    <?php if ($_GET['id'] == $data['gameCode']) { ?>
                        <div class="col-lg-3 col-md-12 col-sm-12 ">
                            <div class="card text-white kartu-produk" style="margin: 10px;">
                                <div class="card-body" style="text-align: center;">
                                    <h4 class="card-title" style="font-size: 20px;"><?= $data['productName']; ?></h4>
                                    <picture><img src="../../assets/images/product/<?= $data['image']; ?>"
                                                  alt="gambar game" class="img-thumbnail mt-3"></picture>
                                    <h6 class="mt-3">Bonus <?= $data['productBonus']; ?></h6>
                                    <h5 class="mt-3">Rp. <?= $data['productPrice']; ?></h5>
                                    <a href="../../routes/add_order.php?id_product=<?= $data['productId']; ?>&&id_game=<?= $id_game; ?>"
                                       class="btn btn-primary"
                                       type="button" style="padding: 6px 25%;margin: 15px;">Add to Cart
                                    </a>
                                </div>
                            </div>
                        </div>
                    <?php } ?>
                <?php } ?>
            </div>
        <?php } else { ?>
            <div class="row">
                <div class="col-md-12 col-sm-12">
                    <h1 style="font-size: 25px;margin: 0;padding: 20px;text-shadow: 2px 2px 3px;text-align: center;">
                        Maaf product Belum ditambahkan oleh Admin
                    </h1>
                </div>
            </div>
        <?php } ?>
    </div>
<?php include "../layout/footer.php"; ?>