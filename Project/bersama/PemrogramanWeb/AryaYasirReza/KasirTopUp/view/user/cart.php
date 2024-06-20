<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <header>
        <nav class="navbar navbar-expand-lg header ">
            <div class="container-fluid justify-content-center">
                <a class="navbar-brand title fs-4" style="color: var(--green);" href="#">Keranjang Anda</a>
            </div>
        </nav>
    </header>
    <div class="container mt-5 mb-5">
        <?php if (!empty($dataOrders)) { ?>
            <div class="row">
                <div class="col-12 col-sm-12 col-md-12 col-lg-6">
                    <?php foreach ($dataOrders as $data) { ?>
                        <?php if ($data['orderPersonEmail'] == $_SESSION['email'] && $data['orderStatus'] == 'not yet paid') { ?>
                            <div class="card mb-3">
                                <div class="card-body shadow">
                                    <div class="row">
                                        <div class="col">
                                            <div class="row">
                                                <div class="col-4 text-center">
                                                    <img class="img-fluid shadow-none p-2"
                                                         src="../../assets/images/product/<?= $data['image']; ?>"
                                                         alt="order">
                                                </div>
                                                <div class="col">
                                                    <p class="mt-2" style="font-size: 15px;">
                                                        <strong>&nbsp; <?= $data['orderProductName']; ?></strong>
                                                    </p>
                                                    <p class="mt-2" style="font-size: 13px;">
                                                        <i class="fa fa-eur">Rp.</i>
                                                        <strong>&nbsp;<?= $data['orderProductPrice']; ?></strong>
                                                    </p>
                                                    <div class="row">
                                                        <div class="col-12 col-sm-6">
                                                        </div>
                                                        <div class="col-sm-12 col-md-6">
                                                            <a href="../../routes/delete_order.php?id=<?= $data['orderId']; ?>"
                                                               class="btn btn-danger d-block w-100">
                                                                Batalkan
                                                            </a>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        <?php } ?>
                    <?php } ?>
                </div>
                <div class="col-12 col-sm-12 col-md-12 col-lg-6">
                    <div class="card text-white kartu-produk">
                        <?php
                        $totalShopping = 0;
                        $totalPurchase = 0;
                        $totalAdmin = 0;
                        $discount = 0;
                        $bill = 0;

                        foreach ($dataOrders as $data) {
                            if ($data['orderPersonEmail'] == $_SESSION['email'] && $data['orderStatus'] == 'not yet paid') {
                                $totalPurchase++;
                                $totalShopping += $data['orderProductPrice'];
                            }
                        }

                        if ($totalPurchase >= 5) {
                            $discount = 10 / 100;
                        }

                        if ($totalPurchase > 0) {
                            $totalAdmin = 1500;
                        }

                        $discount *= $totalShopping;
                        $bill = $totalShopping + $totalAdmin - $discount;
                        ?>
                        <div class="card-body">
                            <div class="row">
                                <div class="col">
                                    <p>Biaya Produk</p>
                                </div>
                                <div class="col">
                                    <p class="text-end">
                                        <i class="fa fa-euro">Rp.</i>
                                        &nbsp; <?= number_format($totalShopping, 0, ",", "."); ?>
                                    </p>
                                </div>
                            </div>
                            <hr style="color: rgb(0,0,0);">
                            <div class="row">
                                <div class="col">
                                    <p>Biaya Admin</p>
                                </div>
                                <div class="col">
                                    <p class="text-end">
                                        <i class="fa fa-euro">Rp.</i>
                                        &nbsp; <?= number_format($totalAdmin, 0, ",", "."); ?>
                                    </p>
                                </div>
                            </div>
                            <hr style="color: rgb(0,0,0);">
                            <div class="row">
                                <div class="col">
                                    <p>Diskon Pembelian</p>
                                </div>
                                <div class="col">
                                    <p class="text-end">
                                        &nbsp;-<i class="fa fa-euro">Rp.</i>
                                        &nbsp; <?= number_format($discount, 0, ",", "."); ?>
                                    </p>
                                </div>
                            </div>
                            <hr style="color: rgb(0,0,0);">
                            <hr style="color: rgb(0,0,0);">
                            <div class="row">
                                <div class="col">
                                    <p style="font-size: 18px;">
                                        <strong>Total</strong>
                                    </p>
                                </div>
                                <div class="col">
                                    <p class="text-end" style="font-size: 18px;">
                                        &nbsp;<i class="fa fa-euro">Rp.</i>
                                        &nbsp; <?= number_format($bill, 0, ",", "."); ?>
                                    </p>
                                </div>
                            </div>
                            <form action="../../routes/update_order.php" method="post">
                                <input type="hidden" name="email" value="<?= $_SESSION['email'];?>">
                                <input type="hidden" name="total_bill" value="<?= $bill?>">
                                <div class="row">
                                    <div class="col">
                                        <div class="form-group mb-3 mt-5">
                                            <label for="money" class="form-label">Jumlah Bayar</label>
                                            <input class="form-control" type="text" name="money" id="money"
                                                   placeholder="Masukan nominal uang" pattern="[0-9]+">
                                        </div>
                                    </div>
                                </div>
                                <hr style="color: rgb(0,0,0);">
                                <div class="row">
                                    <div class="col">
                                        <button class="btn btn-primary d-block w-100"
                                                type="submit">
                                            Pay now
                                        </button>
                                    </div>
                                </div>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        <?php } else { ?>
            <h3 class="text-white text-center">Anda belum menambahkan produk ke keranjang Anda</h3>
        <?php } ?>
    </div>
<?php include "../layout/footer.php"; ?>