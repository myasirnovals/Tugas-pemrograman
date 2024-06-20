<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container">
        <h4 style="color: var(--green); margin-top: 20px;">Products</h4>
        <div class="container" style="margin-top: 10px;">
            <?php
            if (!empty($dataProducts)) {
                $no = 1;
                ?>
                <table class="table table-bordered table-dark table-striped table-responsive mt-5">
                    <thead>
                    <tr class="text-center">
                        <th>No</th>
                        <th>Kode Game</th>
                        <th>Nama Produk</th>
                        <th>Harga Produk</th>
                        <th>Bonus Produk</th>
                        <th>Gambar</th>
                        <th>Aksi</th>
                    </tr>
                    </thead>
                    <tbody>
                    <?php foreach ($dataProducts as $data) { ?>
                        <tr>
                            <td><?= $no++; ?></td>
                            <td><?= $data['gameCode']; ?></td>
                            <td><?= $data['productName']; ?></td>
                            <td class="text-end"><?= $data['productPrice']; ?></td>
                            <td><?= $data['productBonus']; ?></td>
                            <td class="text-center">
                                <img src="../../assets/images/product/<?= $data['image']; ?>"
                                     alt="Games" width="250"
                                     class="img-thumbnail">
                            </td>
                            <td class="text-center">
                                <a href="update_product.php?id=<?= $data['productId'] ?>"
                                   class="btn btn-primary">Edit</a>
                                <a href="../../routes/delete_product.php?id=<?= $data['productId']; ?>"
                                   class="btn btn-danger">Hapus</a>
                            </td>
                        </tr>
                    <?php } ?>
                    </tbody>
                </table>
            <?php } else { ?>
                <p class="text-center">Product belum ditambahkan</p>
            <?php } ?>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>