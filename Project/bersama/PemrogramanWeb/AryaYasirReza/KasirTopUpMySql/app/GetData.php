<?php

function GetProductAmount($data): int
{
    $file_product = "../database/data_product" . ".json";

    $sum = 0;

    if (file_exists("$file_product")) {
        $data_product = file_get_contents("$file_product");
        $array_product = json_decode($data_product, true);

        foreach ($array_product as $product) {
            if ($product["gameCode"] == $data) {
                $sum++;
            }
        }
    }

    return $sum;
}