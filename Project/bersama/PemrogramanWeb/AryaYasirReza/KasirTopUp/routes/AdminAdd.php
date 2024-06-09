<?php
include "../app/AddData.php";

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $file_name = "../database/dataGame" . ".json";

    if (file_put_contents("$file_name", AddGame())) {
        echo "<script>alert('Game berhasil ditambahkan'); document.location.href = '../view/admin/add_game.php';</script>";
    } else {
        echo "<script>alert('Game gagal ditambahkan'); document.location.href = '../view/admin/add_game.php';</script>";
    }
}