<?php
include "../app/UpdateData.php";

session_start();

if (!isset($_SESSION["logged"])) {
    echo "<script>alert('Anda harus login terlebih dahulu');</script>";
    header("Location: ../view/auth/login.php");
    exit();
}

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_product = "../database/data_product" . ".json";

    if (file_put_contents($data_product, UpdateGameProduct())) {
        echo "<script>alert('Produk berhasil di update'); document.location.href = '../view/admin/product.php';</script>";
    } else {
        echo "<script>alert('Produk gagal di update'); document.location.href = '../view/admin/product.php';</script>";
    }
}