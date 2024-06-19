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
                        <?php if ($data['orderPersonEmail'] == $_SESSION['email']) { ?>
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
                                                            <form>
                                                                <div class="form-group mb-3">
                                                                    <label for="quantity" style="font-size: 15px;">Jumlah
                                                                        Produk:</label>
                                                                    <input class="form-control"
                                                                           type="number"
                                                                           placeholder="Qty"
                                                                           min="1" max="10"
                                                                           value="<?= $data['orderProductAmount']; ?>"
                                                                           name="quantity"
                                                                           id="quantity">
                                                                </div>
                                                            </form>
                                                        </div>
                                                        <div class="col">
                                                            <button class="btn btn-outline-dark d-block w-100"
                                                                    type="submit">
                                                                Buy Later
                                                            </button>
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
                        <div class="card-body">
                            <div class="row">
                                <div class="col">
                                    <p>Biaya Produk</p>
                                </div>
                                <div class="col">
                                    <p class="text-end">
                                        <i class="fa fa-euro">Rp.</i>&nbsp; 1234
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
                                        <i class="fa fa-euro">Rp.</i>&nbsp; 42
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
                                        &nbsp;-<i class="fa fa-euro">Rp.</i>&nbsp; 32
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
                                        &nbsp;<i class="fa fa-euro">Rp.</i>&nbsp;1122
                                    </p>
                                </div>
                            </div>
                            <div class="row">
                                <div class="col">
                                    <form>
                                        <div class="form-group mb-3">
                                            <input class="form-control" type="text"
                                                   placeholder="Enter your discount Code">
                                        </div>
                                    </form>
                                </div>
                                <div class="col">
                                    <button class="btn btn-outline-dark d-block w-100" type="button">
                                        Apply Now
                                    </button>
                                </div>
                            </div>
                            <hr style="color: rgb(0,0,0);">
                            <div class="row">
                                <div class="col">
                                    <button class="btn btn-primary d-block w-100" type="button">
                                        Pay now
                                    </button>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        <?php } else { ?>
            <h3 class="text-white text-center">Anda belum menambahkan produk ke keranjang Anda</h3>
        <?php } ?>
    </div>
<?php include "../layout/footer.php"; ?>