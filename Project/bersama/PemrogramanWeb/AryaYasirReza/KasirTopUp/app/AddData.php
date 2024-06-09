<?php

require_once __DIR__ . "/UploadData.php";

function AddGame()
{
    $name = htmlspecialchars($_POST["nameGame"]);
    $description = htmlspecialchars($_POST["description"]);
    $image = UploadsImage();

    if (!$image) {
        return false;
    }

    $file_name = "../database/dataGame" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        $extra = array(
            "nameGame" => $name,
            "description" => $description,
            "image" => $image,
        );

        $array_data[] = $extra;
        return json_encode($array_data);
    } else {
        $dataError = array();
        $dataError[] = array(
            "nameGame" => $name,
            "description" => $description,
            "image" => $image,
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}