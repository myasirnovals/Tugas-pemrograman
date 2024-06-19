<?php

function UploadsImage()
{
    $image_name = $_FILES["image"]["name"];
    $image_size = $_FILES["image"]["size"];
    $image_error = $_FILES["image"]["error"];
    $image_tmp = $_FILES["image"]["tmp_name"];

    // cek apakah ada image atau tidak
    if ($image_error === 4) {
        return "-";
    }

    // cek apakah yang diupload adalah image
    $valid_extension = ["jpg", "jpeg", "png"];
    $image_extension = explode(".", $image_name);
    $image_extension = strtolower(end($image_extension));

    if (!in_array($image_extension, $valid_extension)) {
        echo "<script>alert('Yang Anda upload bukan image!'); </script>";
        return false;
    }

    // cek ukuran image
    if ($image_size > 5097152) {
        echo "<script>alert('Ukuran image terlalu besar!'); </script>";
        return false;
    }

    // upload image
    $image_new_name = "datagame" . uniqid();
    $image_new_name .= ".";
    $image_new_name .= $image_extension;

    move_uploaded_file($image_tmp, "../assets/images/game/" . $image_new_name);

    return $image_new_name;
}

function UploadsImageProduct()
{
    $image_name = $_FILES["image"]["name"];
    $image_size = $_FILES["image"]["size"];
    $image_error = $_FILES["image"]["error"];
    $image_tmp = $_FILES["image"]["tmp_name"];

    // cek apakah ada image atau tidak
    if ($image_error === 4) {
        return "-";
    }

    // cek apakah yang diupload adalah image
    $valid_extension = ["jpg", "jpeg", "png"];
    $image_extension = explode(".", $image_name);
    $image_extension = strtolower(end($image_extension));

    if (!in_array($image_extension, $valid_extension)) {
        echo "<script>alert('Yang Anda upload bukan image!'); </script>";
        return false;
    }

    // cek ukuran image
    if ($image_size > 5097152) {
        echo "<script>alert('Ukuran image terlalu besar!'); </script>";
        return false;
    }

    // upload image
    $image_new_name = "dataproduct" . uniqid();
    $image_new_name .= ".";
    $image_new_name .= $image_extension;

    move_uploaded_file($image_tmp, "../assets/images/product/" . $image_new_name);

    return $image_new_name;
}

function UploadsImageMember()
{
    $image_name = $_FILES["image"]["name"];
    $image_size = $_FILES["image"]["size"];
    $image_error = $_FILES["image"]["error"];
    $image_tmp = $_FILES["image"]["tmp_name"];

    // cek apakah ada image atau tidak
    if ($image_error === 4) {
        return "-";
    }

    // cek apakah yang diupload adalah image
    $valid_extension = ["jpg", "jpeg", "png"];
    $image_extension = explode(".", $image_name);
    $image_extension = strtolower(end($image_extension));

    if (!in_array($image_extension, $valid_extension)) {
        echo "<script>alert('Yang Anda upload bukan image!'); </script>";
        return false;
    }

    // cek ukuran image
    if ($image_size > 5097152) {
        echo "<script>alert('Ukuran image terlalu besar!'); </script>";
        return false;
    }

    // upload image
    $image_new_name = "profile" . uniqid();
    $image_new_name .= ".";
    $image_new_name .= $image_extension;

    move_uploaded_file($image_tmp, "../assets/images/member/" . $image_new_name);

    return $image_new_name;
}

function UploadsImageOrder()
{
    $image_name = $_FILES["image"]["name"];
    $image_size = $_FILES["image"]["size"];
    $image_error = $_FILES["image"]["error"];
    $image_tmp = $_FILES["image"]["tmp_name"];

    // cek apakah ada image atau tidak
    if ($image_error === 4) {
        return "-";
    }

    // cek apakah yang diupload adalah image
    $valid_extension = ["jpg", "jpeg", "png"];
    $image_extension = explode(".", $image_name);
    $image_extension = strtolower(end($image_extension));

    if (!in_array($image_extension, $valid_extension)) {
        echo "<script>alert('Yang Anda upload bukan image!'); </script>";
        return false;
    }

    // cek ukuran image
    if ($image_size > 5097152) {
        echo "<script>alert('Ukuran image terlalu besar!'); </script>";
        return false;
    }

    // upload image
    $image_new_name = "order" . uniqid();
    $image_new_name .= ".";
    $image_new_name .= $image_extension;

    move_uploaded_file($image_tmp, "../assets/images/order/" . $image_new_name);

    return $image_new_name;
}