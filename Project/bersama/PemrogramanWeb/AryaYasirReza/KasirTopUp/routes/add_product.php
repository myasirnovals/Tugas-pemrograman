<?php
include "../app/AddData.php";

session_start();

if (!isset($_SESSION["logged"])) {
    echo "<script>alert('Anda harus login terlebih dahulu');</script>";
    header("Location: ../view/auth/login.php");
    exit();
}

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_product = "../database/data_product" . ".json";

    if (file_put_contents("$data_product", AddGameProduct())) {
        echo "<script>alert('Produk berhasil ditambahkan'); document.location.href = '../view/admin/add_product.php';</script>";
    } else {
        echo "<script>alert('Produk gagal ditambahkan'); document.location.href = '../view/admin/add_product.php';</script>";
    }
}