<?php
include "../app/UpdateData.php";

session_start();

if (!isset($_SESSION["logged"])) {
    echo "<script>alert('Anda harus login terlebih dahulu');</script>";
    header("Location: ../view/auth/login.php");
    exit();
}

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $money = $_POST['money'];
    if ($money == "" || $_POST['total_bill'] == 0) {
        echo "<script>alert('Beli produk terlebih dahulu'); document.location.href = '../view/user/cart.php';</script>";
    } else {
        if ($money < $_POST['total_bill']) {
            echo "<script>alert('Uang yang anda masukan kurang'); document.location.href = '../view/user/cart.php';</script>";
        } else {
            $data_order = "../database/data_order" . ".json";

            if (file_put_contents($data_order, UpdateOrder())) {
                $money -= $_POST['total_bill'];
                if ($money != 0) {
                    echo "<script>alert('Pembayaran berhasil di update, kembalian Anda Rp. $money'); document.location.href = '../view/user/cart.php';</script>";
                } else {
                    echo "<script>alert('Pembayaran berhasil di update'); document.location.href = '../view/user/cart.php';</script>";
                }
            } else {
                echo "<script>alert('Pembayaran gagal di update'); document.location.href = '../view/user/cart.php';</script>";
            }
        }
    }
}