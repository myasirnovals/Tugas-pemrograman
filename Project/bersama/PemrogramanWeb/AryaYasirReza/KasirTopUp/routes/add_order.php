<?php
include "../app/AddData.php";

session_start();

if (!isset($_SESSION["logged"])) {
    echo "<script>alert('Anda harus login terlebih dahulu');</script>";
    header("Location: ../view/auth/login.php");
    exit();
}

if ($_SERVER["REQUEST_METHOD"] === "GET") {
    $data_order = "../database/data_order" . ".json";

    $id = $_GET['id_game'];

    if (file_put_contents("$data_order", AddOrder($_SESSION['email'], $_GET['id_product']))) {
        echo "<script>alert('Pesanan berhasil ditambahkan'); document.location.href = '../view/user/detail_product.php?id=$id';</script>";
    } else {
        echo "<script>alert('Pesanan gagal ditambahkan'); document.location.href = '../view/user/detail_product.php?id=$id';</script>";
    }
}