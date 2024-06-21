<?php
include "../app/UpdateData.php";

session_start();

if (!isset($_SESSION["logged"])) {
    echo "<script>alert('Anda harus login terlebih dahulu');</script>";
    header("Location: ../view/auth/login.php");
    exit();
}

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_member = "../database/data_member" . ".json";

    $data = file_get_contents($data_member);
    $array_data = json_decode($data, true);

    foreach ($array_data as $row) {
        if (($row['email'] == $_POST['email'])) {
            echo "<script>alert('Email sudah digunakan, silahkan ganti dengan email yang lain');</script>";
            echo "<script>alert('Profile gagal di update'); document.location.href = '../view/admin/profile.php';</script>";

            return false;
        }
    }

    if (file_put_contents($data_member, UpdateProfile())) {
        echo "<script>alert('Profile berhasil di update'); document.location.href = '../view/admin/profile.php';</script>";
    } else {
        echo "<script>alert('Profile gagal di update'); document.location.href = '../view/admin/profile.php';</script>";
    }
}