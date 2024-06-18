<?php
require_once __DIR__ . "/GetData.php";

function DeleteGame()
{
    $id = $_GET['id'];

    // get data from database
    $file_game = "../database/data_game" . ".json";
    $file_product = "../database/data_product" . ".json";

    // get data from directory image
    $file_image_game = "../assets/images/game/";
    $file_image_product = "../assets/images/product/";

    if (file_exists("$file_game") && file_exists("$file_product")) {
        $data_game = file_get_contents("$file_game");
        $array_game = json_decode($data_game, true);

        foreach ($array_game as $key_game => $game) {
            if ($game["kodeGame"] == $id) {
                $data_product = file_get_contents("$file_product");
                $array_product = json_decode($data_product, true);

                foreach ($array_product as $key_product => $product) {
                    if ($product["gameCode"] == $game["kodeGame"]) {
                        array_splice($array_product, $key_product, GetUserAmount($game["kodeGame"]));
                    }

                    // remove all image from directory
                    unlink("$file_image_product" . $product['image']);
                }
                $array_product = json_encode($array_product, JSON_PRETTY_PRINT);
                file_put_contents($file_product, $array_product);

                // remove image from directory
                unlink("$file_image_game" . $game['image']);

                array_splice($array_game, $key_game, 1);
            }
        }


        return json_encode($array_game, JSON_PRETTY_PRINT);

    } else {
        return "Data not exist <br>";
    }
}

function DeleteGameProduct()
{
    $id = $_GET['id'];

    $file_name = "../database/data_product" . ".json";
    $file_image = "../assets/images/product/";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        foreach ($array_data as $key => $value) {
            if ($value["productId"] == $id) {
                unlink("$file_image" . $value['image']);
                array_splice($array_data, $key, 1);
            }
        }

        return json_encode($array_data, JSON_PRETTY_PRINT);

    } else {
        return "Data not exist <br>";
    }
}