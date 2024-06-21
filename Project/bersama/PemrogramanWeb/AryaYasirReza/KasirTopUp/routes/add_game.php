<?php
include "../app/AddData.php";

session_start();

if (!isset($_SESSION["logged"])) {
    echo "<script>alert('Anda harus login terlebih dahulu');</script>";
    header("Location: ../view/auth/login.php");
    exit();
}

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_game = "../database/data_game" . ".json";

    if (file_put_contents("$data_game", AddGame())) {
        echo "<script>alert('Game berhasil ditambahkan'); document.location.href = '../view/admin/add_game.php';</script>";
    } else {
        echo "<script>alert('Game gagal ditambahkan'); document.location.href = '../view/admin/add_game.php';</script>";
    }
}