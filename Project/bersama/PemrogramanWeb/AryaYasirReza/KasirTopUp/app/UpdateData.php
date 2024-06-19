<?php

require_once __DIR__ . "/UploadData.php";

date_default_timezone_set('Asia/Jakarta');

function UpdateGame()
{
    $gameId = $_POST["gameId"];
    $name = htmlspecialchars($_POST["gameName"]);
    $old_image = htmlspecialchars($_POST["old_image"]);
    $updated_at = date('l, d / M / Y  H:i:s');

    $file_image_game = "../assets/images/game/";

    if ($_FILES['image']['error'] === 4) {
        $image = $old_image;
    } else {
        if ($old_image != "") {
            unlink("$file_image_game" . $old_image);
        }
        $image = UploadsImage();
    }

    $file_name = "../database/data_game" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        foreach ($array_data as $key => $value) {
            if ($value["gameId"] == $gameId) {
                $array_data[$key]["gameName"] = $name;
                $array_data[$key]["image"] = $image;
                $array_data[$key]["updated_at"] = $updated_at;
            }
        }

        return json_encode($array_data, JSON_PRETTY_PRINT);

    } else {
        $dataError = array();
        $dataError[] = array(
            "gameId" => $gameId,
            "gameName" => $name,
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

    $file_image_product = "../assets/images/product/";

    if ($_FILES['image']['error'] === 4) {
        $image = $old_image;
    } else {
        if ($old_image != "") {
            unlink("$file_image_product" . $old_image);
        }
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

function UpdateMember() {
    $id = $_POST['memberId'];

    $username = htmlspecialchars($_POST["username"]);
    $phone = htmlspecialchars($_POST["phone"]);
    $members = htmlspecialchars($_POST["members"]);

    $updated_at = date('l, d / M / Y  H:i:s');

    $file_name = "../database/data_member" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        foreach ($array_data as $key => $value) {
            if ($value["memberId"] == $id) {
                $array_data[$key]["username"] = $username;
                $array_data[$key]["phone"] = $phone;
                $array_data[$key]["members"] = $members;
                $array_data[$key]["updated_at"] = $updated_at;
            }
        }

        return json_encode($array_data, JSON_PRETTY_PRINT);

    } else {
        $dataError = array();
        $dataError[] = array(
            "memberId" => $id,
            "username" => $username,
            "phone" => $phone,
            "members" => $members,
            "updated_at" => $updated_at
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}