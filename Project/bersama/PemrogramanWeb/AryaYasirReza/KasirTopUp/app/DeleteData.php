<?php
function DeleteGame()
{
    $id = $_GET['id'];

    $file_name = "../database/data_game" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        foreach ($array_data as $key => $value) {
            if ($value["kodeGame"] == $id) {
                array_splice($array_data, $key, 1);
            }
        }

        return json_encode($array_data, JSON_PRETTY_PRINT);

    } else {
        return "Data not exist <br>";
    }
}