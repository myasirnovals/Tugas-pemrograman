<?php
include "../app/UpdateData.php";

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_member = "../database/data_member" . ".json";

    if (file_put_contents($data_member, UpdateProfile())) {
        echo "<script>alert('Profile berhasil di update'); document.location.href = '../view/admin/home.php';</script>";
    } else {
        echo "<script>alert('Profile gagal di update'); document.location.href = '../view/admin/home.php';</script>";
    }
}