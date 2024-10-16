<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container">
        <div class="container" style="margin-top: 10px;">
            <div class="container mt-5">
                <h2 style="text-align: center;margin: 15px 0;">Welcome, <?= $_SESSION['name']; ?></h2>
            </div>
            <div class="container py-4 py-xl-5">
                <div class="row gy-4 row-cols-2 row-cols-md-4">
                    <div class="col">
                        <div class="text-center d-flex flex-column justify-content-center align-items-center py-3">
                            <div class="bs-icon-xl bs-icon-circle bs-icon-primary d-flex flex-shrink-0 justify-content-center align-items-center d-inline-block mb-2 bs-icon lg">
                                <svg xmlns="http://www.w3.org/2000/svg" width="1em" height="1em" fill="currentColor"
                                     viewBox="0 0 16 16" class="bi bi-bell">
                                    <path d="M8 16a2 2 0 0 0 2-2H6a2 2 0 0 0 2 2M8 1.918l-.797.161A4.002 4.002 0 0 0 4 6c0 .628-.134 2.197-.459 3.742-.16.767-.376 1.566-.663 2.258h10.244c-.287-.692-.502-1.49-.663-2.258C12.134 8.197 12 6.628 12 6a4.002 4.002 0 0 0-3.203-3.92L8 1.917zM14.22 12c.223.447.481.801.78 1H1c.299-.199.557-.553.78-1C2.68 10.2 3 6.88 3 6c0-2.42 1.72-4.44 4.005-4.901a1 1 0 1 1 1.99 0A5.002 5.002 0 0 1 13 6c0 .88.32 4.2 1.22 6"></path>
                                </svg>
                            </div>
                            <div class="px-3">
                                <?php
                                $no = 0;
                                if (!empty($dataOrders)) {

                                    foreach ($dataOrders as $order) {
                                        if ($order['orderStatus'] == "paid") {
                                            $no++;
                                        }
                                    }
                                    ?>
                                    <h2 class="fw-bold mb-0"><?= $no; ?></h2>
                                <?php } else { ?>
                                    <h2 class="fw-bold mb-0"><?= $no; ?></h2>
                                <?php } ?>
                                <p class="mb-0">Penjualan</p>
                            </div>
                        </div>
                    </div>
                    <div class="col">
                        <div class="text-center d-flex flex-column justify-content-center align-items-center py-3">
                            <div class="bs-icon-xl bs-icon-circle bs-icon-primary d-flex flex-shrink-0 justify-content-center align-items-center d-inline-block mb-2 bs-icon lg">
                                <svg xmlns="http://www.w3.org/2000/svg" width="1em" height="1em" fill="currentColor"
                                     viewBox="0 0 16 16" class="bi bi-bezier">
                                    <path fill-rule="evenodd"
                                          d="M0 10.5A1.5 1.5 0 0 1 1.5 9h1A1.5 1.5 0 0 1 4 10.5v1A1.5 1.5 0 0 1 2.5 13h-1A1.5 1.5 0 0 1 0 11.5zm1.5-.5a.5.5 0 0 0-.5.5v1a.5.5 0 0 0 .5.5h1a.5.5 0 0 0 .5-.5v-1a.5.5 0 0 0-.5-.5zm10.5.5A1.5 1.5 0 0 1 13.5 9h1a1.5 1.5 0 0 1 1.5 1.5v1a1.5 1.5 0 0 1-1.5 1.5h-1a1.5 1.5 0 0 1-1.5-1.5zm1.5-.5a.5.5 0 0 0-.5.5v1a.5.5 0 0 0 .5.5h1a.5.5 0 0 0 .5-.5v-1a.5.5 0 0 0-.5-.5zM6 4.5A1.5 1.5 0 0 1 7.5 3h1A1.5 1.5 0 0 1 10 4.5v1A1.5 1.5 0 0 1 8.5 7h-1A1.5 1.5 0 0 1 6 5.5zM7.5 4a.5.5 0 0 0-.5.5v1a.5.5 0 0 0 .5.5h1a.5.5 0 0 0 .5-.5v-1a.5.5 0 0 0-.5-.5z"></path>
                                    <path d="M6 4.5H1.866a1 1 0 1 0 0 1h2.668A6.517 6.517 0 0 0 1.814 9H2.5c.123 0 .244.015.358.043a5.517 5.517 0 0 1 3.185-3.185A1.503 1.503 0 0 1 6 5.5zm3.957 1.358A1.5 1.5 0 0 0 10 5.5v-1h4.134a1 1 0 1 1 0 1h-2.668a6.517 6.517 0 0 1 2.72 3.5H13.5c-.123 0-.243.015-.358.043a5.517 5.517 0 0 0-3.185-3.185z"></path>
                                </svg>
                            </div>
                            <div class="px-3">
                                <?php
                                $no = 0;
                                if (!empty($dataMembers)) {
                                    foreach ($dataMembers as $member) {
                                        $no++;
                                    }
                                    ?>
                                    <h2 class="fw-bold mb-0"><?= $no; ?></h2>
                                <?php } else { ?>
                                    <h2 class="fw-bold mb-0"><?= $no; ?></h2>
                                <?php } ?>
                                <p class="mb-0">Member</p>
                            </div>
                        </div>
                    </div>
                    <div class="col">
                        <div class="text-center d-flex flex-column justify-content-center align-items-center py-3">
                            <div class="bs-icon-xl bs-icon-circle bs-icon-primary d-flex flex-shrink-0 justify-content-center align-items-center d-inline-block mb-2 bs-icon lg">
                                <svg xmlns="http://www.w3.org/2000/svg" width="1em" height="1em" fill="currentColor"
                                     viewBox="0 0 16 16" class="bi bi-cup">
                                    <path fill-rule="evenodd"
                                          d="M.11 3.187A.5.5 0 0 1 .5 3h13a.5.5 0 0 1 .488.608l-.22.991a3.001 3.001 0 0 1-1.3 5.854l-.132.59A2.5 2.5 0 0 1 9.896 13H4.104a2.5 2.5 0 0 1-2.44-1.958L.012 3.608a.5.5 0 0 1 .098-.42Zm12.574 6.288a2 2 0 0 0 .866-3.899l-.866 3.9ZM1.124 4l1.516 6.825A1.5 1.5 0 0 0 4.104 12h5.792a1.5 1.5 0 0 0 1.464-1.175L12.877 4H1.123Z"></path>
                                </svg>
                            </div>
                            <div class="px-3">
                                <?php
                                $no = 0;
                                if (!empty($dataGames)) {
                                    foreach ($dataGames as $game) {
                                        $no++;
                                    }
                                    ?>
                                    <h2 class="fw-bold mb-0"><?= $no; ?></h2>
                                <?php } else { ?>
                                    <h2 class="fw-bold mb-0"><?= $no; ?></h2>
                                <?php } ?>
                                <p class="mb-0">Game</p>
                            </div>
                        </div>
                    </div>
                    <div class="col">
                        <div class="text-center d-flex flex-column justify-content-center align-items-center py-3">
                            <div class="bs-icon-xl bs-icon-circle bs-icon-primary d-flex flex-shrink-0 justify-content-center align-items-center d-inline-block mb-2 bs-icon lg">
                                <svg xmlns="http://www.w3.org/2000/svg" width="1em" height="1em" fill="currentColor"
                                     viewBox="0 0 16 16" class="bi bi-cart2">
                                    <path d="M0 2.5A.5.5 0 0 1 .5 2H2a.5.5 0 0 1 .485.379L2.89 4H14.5a.5.5 0 0 1 .485.621l-1.5 6A.5.5 0 0 1 13 11H4a.5.5 0 0 1-.485-.379L1.61 3H.5a.5.5 0 0 1-.5-.5M3.14 5l1.25 5h8.22l1.25-5H3.14zM5 13a1 1 0 1 0 0 2 1 1 0 0 0 0-2m-2 1a2 2 0 1 1 4 0 2 2 0 0 1-4 0m9-1a1 1 0 1 0 0 2 1 1 0 0 0 0-2m-2 1a2 2 0 1 1 4 0 2 2 0 0 1-4 0"></path>
                                </svg>
                            </div>
                            <div class="px-3">
                                <?php
                                $no = 0;
                                if (!empty($dataProducts)) {
                                    foreach ($dataProducts as $product) {
                                        $no++;
                                    }
                                    ?>
                                    <h2 class="fw-bold mb-0"><?= $no; ?></h2>
                                <?php } else { ?>
                                    <h2 class="fw-bold mb-0"><?= $no; ?></h2>
                                <?php } ?>
                                <p class="mb-0">Product</p>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <hr>
            <div class="container mt-5">
                <h4>History Order</h4>
                <div class="container" style="margin-top: 10px;">
                    <?php
                    if (!empty($dataOrders)) {
                        $no = 1;
                        ?>
                        <table class="table table-bordered table-dark table-striped table-responsive mt-5">
                            <thead>
                            <tr class="text-center">
                                <th>No</th>
                                <th>Nama Pemesan</th>
                                <th>Email</th>
                                <th>Nama Produk</th>
                                <th>Harga Produk</th>
                                <th>Kode Produk</th>
                                <th>Gambar Produk</th>
                                <th>Status Pesanan</th>
                                <th>Aksi</th>
                            </tr>
                            </thead>
                            <tbody>
                            <?php foreach ($dataOrders as $data) { ?>
                                <tr>
                                    <td><?= $no++; ?></td>
                                    <td><?= $data['orderPersonName']; ?></td>
                                    <td><?= $data['orderPersonEmail']; ?></td>
                                    <td><?= $data['orderProductName']; ?></td>
                                    <td class="text-end"><?= $data['orderProductPrice']; ?></td>
                                    <td><?= $data['orderProductCode']; ?></td>
                                    <td class="text-center">
                                        <img src="../../assets/images/product/<?= $data['orderProductImage']; ?>"
                                             alt="order" width="250"
                                             class="img-thumbnail">
                                    </td>
                                    <td><?= $data['orderStatus']; ?></td>
                                    <td class="text-center">
                                        <a href="detail_order.php?id=<?= $data['orderId'] ?>"
                                           class="btn btn-primary">Detail</a>
                                    </td>
                                </tr>
                            <?php } ?>
                            </tbody>
                        </table>
                    <?php } else { ?>
                        <p class="text-center">Tidak ada pesanan</p>
                    <?php } ?>
                </div>
            </div>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>