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
    $id = $_POST["productId"];
    $product_name = htmlspecialchars($_POST["productName"]);
    $product_price = htmlspecialchars($_POST["productPrice"]);
    $product_bonus = htmlspecialchars($_POST["productBonus"]);
    $old_image = htmlspecialchars($_POST["old_image"]);
    $updated_at = date('l, d / M / Y  H:i:s');

    if ($_FILES['image']['error'] === 4) {
        $image = $old_image;
    } else {
        $image = UploadsImageProduct();
    }

    $file_name = "../database/data_product" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        foreach ($array_data as $key => $value) {
            if ($value["productId"] == $id) {
                $array_data[$key]["productName"] = $product_name;
                $array_data[$key]["productPrice"] = $product_price;
                $array_data[$key]["productBonus"] = $product_bonus;
                $array_data[$key]["image"] = $image;
                $array_data[$key]["updated_at"] = $updated_at;
            }
        }

        return json_encode($array_data, JSON_PRETTY_PRINT);

    } else {
        $dataError = array();
        $dataError[] = array(
            "productId" => $id,
            "productName" => $product_name,
            "productPrice" => $product_price,
            "productBonus" => $product_bonus,
            "image" => $image,
            "updated_at" => $updated_at
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}