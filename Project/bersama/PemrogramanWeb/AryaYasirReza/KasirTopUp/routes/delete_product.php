<?php
include "../app/DeleteData.php";

session_start();

if (!isset($_SESSION["logged"])) {
    echo "<script>alert('Anda harus login terlebih dahulu');</script>";
    header("Location: ../view/auth/login.php");
    exit();
}

$data_product = "../database/data_product" . ".json";

if (file_put_contents($data_product, DeleteGameProduct())) {
    echo "<script>alert('Produk berhasil di hapus'); document.location.href = '../view/admin/product.php';</script>";
} else {
    echo "<script>alert('Product gagal di hapus'); document.location.href = '../view/admin/product.php';</script>";
}