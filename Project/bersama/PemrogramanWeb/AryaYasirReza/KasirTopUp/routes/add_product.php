<?php
include "../app/AddData.php";

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_product = "../database/data_product" . ".json";

    if (file_put_contents("$data_product", AddGameProduct())) {
        echo "<script>alert('Produk berhasil ditambahkan'); document.location.href = '../view/admin/add_product.php';</script>";
    } else {
        echo "<script>alert('Produk gagal ditambahkan'); document.location.href = '../view/admin/add_product.php';</script>";
    }
}