<?php

function get_data()
{
    $nama = $_POST["nama"];
    $nim = $_POST["nim"];
    $kelas = $_POST["kelas"];
    $angkatan = $_POST["angkatan"];
    $deskripsi = $_POST["deskripsi"];

    // upload gambar
    $image = uploadsImage();

    if (!$image) {
        return false;
    }

    $file_name = "../../database/dataMahasiswa" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        $extra = array(
            "nim" => $nim,
            "nama" => $nama,
            "kelas" => $kelas,
            "angkatan" => $angkatan,
            "image" => $image,
            "deskripsi" => $deskripsi,
        );

        $array_data[] = $extra;
        echo "File exist<br>";
        return json_encode($array_data);
    } else {
        $dataError = array();
        $dataError[] = array(
            "nim" => $nim,
            "nama" => $nama,
            "kelas" => $kelas,
            "angkatan" => $angkatan,
            "image" => $image,
            "deskripsi" => $deskripsi,
        );

        echo "File not exist<br>";
        return json_encode($dataError);
    }
}

function uploadsImage()
{
    $image_name = $_FILES["gambar"]["name"];
    $image_size = $_FILES["gambar"]["size"];
    $image_error = $_FILES["gambar"]["error"];
    $image_tmp = $_FILES["gambar"]["tmp_name"];

    // cek apakah ada gambar atau tidak
    if ($image_error === 4) {
        return "-";
    }

    // cek apakah yang diupload adalah gambar
    $valid_extension = ["jpg", "jpeg", "png"];
    $image_extension = explode(".", $image_name);
    $image_extension = strtolower(end($image_extension));

    if (!in_array($image_extension, $valid_extension)) {
        echo "<script>alert('Yang Anda upload bukan gambar!'); </script>";
        return false;
    }

    // cek ukuran gambar
    if ($image_size > 2097152) {
        echo "<script>alert('Ukuran gambar terlalu besar!'); </script>";
        return false;
    }

    // upload gambar
    $image_new_name = uniqid();
    $image_new_name .= ".";
    $image_new_name .= $image_extension;

    move_uploaded_file($image_tmp, "../../assets/img/" . $image_new_name);

    return $image_new_name;
}