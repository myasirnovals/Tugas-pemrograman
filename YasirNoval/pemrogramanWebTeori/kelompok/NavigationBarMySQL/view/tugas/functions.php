<?php

include "../../config/connection.php";

function get_data()
{
    global $connect;
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

    if ($nim === "") {
        echo "<script>alert('Nim belum diisi'); history.go(-1);</script>";
    }

    if ($nama === "") {
        echo "<script>alert('Nama belum diisi'); history.go(-1);</script>";
    }

    if ($kelas === "") {
        echo "<script>alert('Kelas belum diisi'); history.go(-1);</script>";
    }

    if ($angkatan === "") {
        echo "<script>alert('Angkatan belum diisi'); history.go(-1);</script>";
    }

    // cek apakah nim sudah digunakan atau belum
    $query = "SELECT * FROM mahasiswa WHERE nim = '$nim'";
    $result = mysqli_query($connect, $query);

    $jumlah_data = mysqli_num_rows($result);
    if ($jumlah_data >= 1) {
        echo "<script>alert('NIM sudah digunakan'); history.go(-1);</script>";
    } else {
        // query untuk insert data mahasiswa
        $query = "INSERT INTO mahasiswa (nim, nama, kelas, angkatan, image, deskripsi) 
                  VALUES ('$nim', '$nama', '$kelas', '$angkatan', '$image', '$deskripsi')";

        mysqli_query($connect, $query);
        echo "<script>alert('Data yang anda masukan sukses'); window.location = '../index.php';</script>";
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