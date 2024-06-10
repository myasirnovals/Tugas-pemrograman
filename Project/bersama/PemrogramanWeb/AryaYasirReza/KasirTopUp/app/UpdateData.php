<?php

require_once __DIR__ . "/UploadData.php";

date_default_timezone_set('Asia/Jakarta');

function UpdateGame()
{
    $id = $_POST["kodeGame"];
    $name = htmlspecialchars($_POST["nameGame"]);
    $old_image = htmlspecialchars($_POST["old_image"]);
    $updated_at = date('l, d / M / Y  H:i:s');

    if ($_FILES['image']['error'] === 4) {
        $image = $old_image;
    } else {
        $image = UploadsImage();
    }

    $file_name = "../database/data_game" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        foreach ($array_data as $key => $value) {
            if ($value["kodeGame"] == $id) {
                $array_data[$key]["nameGame"] = $name;
                $array_data[$key]["image"] = $image;
                $array_data[$key]["updated_at"] = $updated_at;
            }
        }

        return json_encode($array_data, JSON_PRETTY_PRINT);

    } else {
        $dataError = array();
        $dataError[] = array(
            "kodeGame" => $id,
            "nameGame" => $name,
            "image" => $image,
            "updated_at" => $updated_at
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}

function UpdateGameProduct()
{
    $product_id = uniqid();
    $product_name = htmlspecialchars($_POST["name"]);
    $product_price = htmlspecialchars($_POST["price"]);
    $product_bonus = htmlspecialchars($_POST["bonus"]);
    $product_code = htmlspecialchars($_POST["gameCode"]);
    $image = UploadsImageProduct();
    $created_at = date('l, d / M / Y  H:i:s');
    $updated_at = date('l, d / M / Y  H:i:s');

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
            "gameCode" => $product_code,
            "image" => $image,
            "created_at" => $created_at,
            "updated_at" => $updated_at
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
            "gameCode" => $product_code,
            "image" => $image,
            "created_at" => $created_at,
            "updated_at" => $updated_at
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}