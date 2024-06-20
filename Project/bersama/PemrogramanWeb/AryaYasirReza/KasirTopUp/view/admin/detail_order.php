<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container mt-5">
        <h4 style="color: var(--green); margin-top: 20px;">Edit Produk:</h4>
        <div class="card mt-5 text-white kartu">
            <div class="container">
                <?php foreach ($dataOrders as $data) { ?>
                    <?php if ($data['orderId'] == $id) { ?>
                        <div class="row pt-3">
                            <div class="row">
                                <div class="col-md-4 col-sm-12">
                                    <img src="../../assets/images/product/<?= $data['image']; ?>" alt="order"
                                         class="img-thumbnail">
                                </div>
                                <div class="col-md-8 col-sm-12 border p-2">
                                    <div class="row">
                                        <div class="col-3">Nama: <br><?= $data['orderPersonName']; ?></div>
                                        <div class="col-3">Email: <br><?= $data['orderPersonEmail']; ?></div>
                                        <div class="col-3">Produk: <br><?= $data['orderProductName']; ?></div>
                                        <div class="col-3">Harga: <br><?= $data['orderProductPrice']; ?></div>
                                    </div>
                                    <hr>
                                    <hr>
                                    <div class="row">
                                        <div class="col-3">Kode Produk: <br><?= $data['orderProductCode']; ?></div>
                                        <div class="col-3">Status: <br><?= $data['orderStatus']; ?></div>
                                        <div class="col-3">Tanggal dibuat: <br><?= $data['created_at']; ?></div>
                                        <div class="col-3">Tanggal beli: <br><?= $data['updated_at']; ?></div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    <?php } ?>
                <?php } ?>
            </div>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>