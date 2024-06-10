<?php
include "../app/UpdateData.php";

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_game = "../database/data_game" . ".json";

    if (file_put_contents($data_game, UpdateGame())) {
        echo "<script>alert('Game berhasil di update'); document.location.href = '../view/admin/add_game.php';</script>";
    } else {
        echo "<script>alert('Game gagal di update'); document.location.href = '../view/admin/add_game.php';</script>";
    }
}