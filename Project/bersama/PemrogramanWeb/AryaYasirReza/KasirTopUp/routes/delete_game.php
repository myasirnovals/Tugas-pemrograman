<?php
include "../app/DeleteData.php";

session_start();

if (!isset($_SESSION["logged"])) {
    echo "<script>alert('Anda harus login terlebih dahulu');</script>";
    header("Location: ../view/auth/login.php");
    exit();
}

$data_game = "../database/data_game" . ".json";

if (file_put_contents($data_game, DeleteGame())) {
    echo "<script>alert('Game berhasil di hapus'); document.location.href = '../view/admin/add_game.php';</script>";
} else {
    echo "<script>alert('Game gagal di hapus'); document.location.href = '../view/admin/add_game.php';</script>";
}