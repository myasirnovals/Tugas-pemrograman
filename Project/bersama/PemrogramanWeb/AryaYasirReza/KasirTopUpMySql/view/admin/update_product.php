<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container mt-5">
        <h4 style="color: var(--green); margin-top: 20px;">Edit Produk:</h4>
        <div class="card mt-5 text-white kartu">
            <div class="container">
                <?php foreach ($dataProducts as $data) { ?>
                    <?php if ($data['productId'] == $id) { ?>
                        <div class="row pt-3">
                            <div class="col-lg-6 col-sm-12 text-center">
                                <img src="../../assets/images/product/<?= $data['image']; ?>" alt="Games" width="250"
                                     class="img-thumbnail">
                                <h5 class="pt-2"><?= $data['productName'] ?></h5>
                            </div>
                            <div class="col-lg-6 col-sm-12">
                                <div class="container">
                                    <form action="../../routes/update_product.php" method="post" enctype="multipart/form-data">
                                        <input type="hidden" name="productId" value="<?= $data['productId']; ?>">
                                        <input type="hidden" name="old_image" value="<?= $data['image']; ?>">
                                        <div class="mb-3">
                                            <label for="productName" class="form-label">Nama Produk</label>
                                            <input type="text" class="form-control" id="productName" name="productName"
                                                   aria-describedby="productName"
                                                   value="<?= $data['productName'] ?>"
                                                   required>
                                            <div id="productName" class="form-text text-white
                                        <div class="mb-3">
                                            <label for="productPrice" class="form-label">Harga Produk</label>
                                            <input type="text" class="form-control" id="productPrice"
                                                   name="productPrice"
                                                   value="<?= $data['productPrice'] ?>"
                                                   required>
                                        </div>
                                        <div class="mb-3">
                                            <label for="productBonus" class="form-label">Bonus Produk</label>
                                            <input type="text" class="form-control" id="productBonus"
                                                   name="productBonus"
                                                   value="<?= $data['productBonus'] ?>"
                                                   required>
                                        </div>
                                        <div class="mb-3">
                                            <label for="image" class="form-label">Game Image</label>
                                            <input type="file" class="form-control" id="image" name="image">
                                        </div>
                                        <button type="submit" class="btn btn-primary mt-3 mb-4">Update Produk</button>
                                    </form>
                                </div>
                            </div>
                        </div>
                    <?php } ?>
                <?php } ?>
            </div>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>