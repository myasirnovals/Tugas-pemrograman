<?php
include "../app/AddData.php";

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_member = "../database/data_member" . ".json";

    if (file_put_contents("$data_member", AddDataUser())) {
        echo "<script>alert('Registrasi berhasil ditambahkan'); document.location.href = '../view/auth/login.php';</script>";
    } else {
        echo "<script>alert('Registrasi gagal ditambahkan'); document.location.href = '../view/auth/register.php';</script>";
    }
}