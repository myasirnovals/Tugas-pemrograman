<?php
include "../app/DeleteData.php";

session_start();

if (!isset($_SESSION["logged"])) {
    echo "<script>alert('Anda harus login terlebih dahulu');</script>";
    header("Location: ../view/auth/login.php");
    exit();
}

$data_order = "../database/data_order" . ".json";

if (file_put_contents($data_order, DeleteOrder($_SESSION['email']))) {
    echo "<script>alert('Pesanan Anda berhasil di batalkan'); document.location.href = '../view/user/cart.php';</script>";
} else {
    echo "<script>alert('Pesanan Anda gagal di batalkan'); document.location.href = '../view/user/cart.php';</script>";
}