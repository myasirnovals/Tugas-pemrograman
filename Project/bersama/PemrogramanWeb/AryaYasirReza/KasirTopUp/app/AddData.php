<?php

require_once __DIR__ . "/UploadData.php";

function AddGame()
{
    $id = uniqid();
    $name = htmlspecialchars($_POST["nameGame"]);
    $description = htmlspecialchars($_POST["description"]);
    $image = UploadsImage();
    $created_at = ;
    $update_at = ;

    if (!$image) {
        return false;
    }

    $file_name = "../database/data_game" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        $extra = array(
            "kodeGame" => $id,
            "nameGame" => $name,
            "description" => $description,
            "image" => $image,
        );

        $array_data[] = $extra;
        return json_encode($array_data);
    } else {
        $dataError = array();
        $dataError[] = array(
            "kodeGame" => $id,
            "nameGame" => $name,
            "description" => $description,
            "image" => $image,
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}

function AddGameProduct()
{
    $product_id = uniqid();
    $product_name = htmlspecialchars($_POST["name"]);
    $product_price = htmlspecialchars($_POST["price"]);
    $product_bonus = htmlspecialchars($_POST["bonus"]);
    $product_code = htmlspecialchars($_POST["productCode"]);
    $image = UploadsImageProduct();
    $created_at = ;
    $update_at = ;

    if (!$image) {
        return false;
    }

    $file_name = "../database/data_product" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        $extra = array(
            "productId" => $product_id,
            "productName" => $product_name,
            "productPrice" => $product_price,
            "productBonus" => $product_bonus,
            "productCode" => $product_code,
            "image" => $image,
        );

        $array_data[] = $extra;
        return json_encode($array_data);
    } else {
        $dataError = array();
        $dataError[] = array(
            "productId" => $product_id,
            "productName" => $product_name,
            "productPrice" => $product_price,
            "productBonus" => $product_bonus,
            "productCode" => $product_code,
            "image" => $image,
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}