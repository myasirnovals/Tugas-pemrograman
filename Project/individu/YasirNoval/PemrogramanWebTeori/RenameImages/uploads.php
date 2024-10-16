<?php

ini_set('max_file_uploads', '150');

// keywords
$keyword = $_POST['keywords'];

// image file
if (isset($_POST['submit'])) {
    // file uploads config
    $folder = date("YmdHis");
    $target_directory = "rename_images/$folder/";
    mkdir($target_directory, 0755);

    $allow_types = array('jpg', 'jpeg', 'png');

    /*TODO Error handling for this message*/
    $status_message = $error_message = $error_upload = $error_upload_type = "";

    $image_name = array_filter($_FILES["renameImages"]["name"]);
    if (!empty($image_name)) {

        foreach ($_FILES["renameImages"]["name"] as $key => $val) {
            // File upload path
            $image_name = basename($_FILES["renameImages"]["name"][$key]);

            if ($keyword != "" && (isset($_POST["position"]) && $_POST["position"] == "start")) {
                $target_file_path = $target_directory . $keyword . "_" . strtolower(str_replace("-", "_", $image_name));
            } else if ($keyword != "" && (isset($_POST["position"]) && $_POST["position"] == "end")) {
                $replace = str_replace("-", "_", $image_name);
                $target_file_path = $target_directory . strtolower(str_replace(".", "_" . $keyword . ".", $replace));
            } else {
                $target_file_path = $target_directory . strtolower(str_replace("-", "_", $image_name));
            }

            // check file type is valid
            $fileType = pathinfo($target_file_path, PATHINFO_EXTENSION);
            if (in_array($fileType, $allow_types)) {
                // Upload file
                move_uploaded_file($_FILES["renameImages"]["tmp_name"][$key], $target_file_path);
            }
        }
    }
}

header("Location: index.php");