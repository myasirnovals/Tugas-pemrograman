<?php
// path
$pathDataGame = "../../database/data_game.json";
$pathDataProduct = "../../database/data_product.json";

// convert
$dataGameString = file_get_contents($pathDataGame);
$dataProductString = file_get_contents($pathDataProduct);

// result
$dataGames = json_decode($dataGameString, true);
$dataProducts = json_decode($dataProductString, true);
?>

<!DOCTYPE html>
<html data-bs-theme="light" lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
    <title>kasir top up game</title>
    <link rel="stylesheet" href="../../assets/bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="../../assets/css/Features-Image-images.css">
    <link rel="stylesheet" href="../../assets/css/Footer-Basic-icons.css">
</head>
<body>
