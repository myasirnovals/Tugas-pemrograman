<?php
// path
session_start();

$pathDataGame = "../../database/data_game.json";
$pathDataProduct = "../../database/data_product.json";
$pathDataMember = "../../database/data_member.json";
$pathDataOrder = "../../database/data_order.json";

// convert
$dataGameString = file_get_contents($pathDataGame);
$dataProductString = file_get_contents($pathDataProduct);
$dataMemberString = file_get_contents($pathDataMember);
$dataOrderString = file_get_contents($pathDataOrder);

// result
$dataGames = json_decode($dataGameString, true);
$dataProducts = json_decode($dataProductString, true);
$dataMembers = json_decode($dataMemberString, true);
$dataOrders = json_decode($dataOrderString, true);

// Get data in url
if (isset($_GET['id'])) {
$id = $_GET['id'];
}
?>

<!DOCTYPE html>
<html data-bs-theme="light" lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
    <title>Top Up Store</title>

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="../../assets/bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="../../assets/css/Features-Image-images.css">
    <link rel="stylesheet" href="../../assets/css/Footer-Basic-icons.css">

    <!-- jQuery -->
    <script src="../../assets/bootstrap/js/jquery-3.7.1.min.js"></script>
</head>
<body>
<?php include "nav_bar.php";
include "main_content.php"; ?>
<?php include "../layout/footer.php"; ?>