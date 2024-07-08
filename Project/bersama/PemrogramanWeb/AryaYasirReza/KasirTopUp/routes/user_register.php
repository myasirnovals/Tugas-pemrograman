<?php
include "../app/AddData.php";

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_member = "../database/data_member" . ".json";

    $data = file_get_contents($data_member);
    $array_data = json_decode($data, true);

    foreach ($array_data as $row) {
        if (($row['email'] == $_POST['email']) || ($row['phone'] == $_POST['phone']) || ($row['username'] == $_POST['username'])) {
            if (($row['email'] == $_POST['email'])) {
                echo "<script>alert('Email sudah ada, anda tidak perlu registrasi lagi');</script>";
            } elseif (($row['phone'] == $_POST['phone'])) {
                echo "<script>alert('Nomor sudah digunakan, silahkan ganti terlebih dahulu jika ingin registrasi');</script>";
            } elseif (($row['username'] == $_POST['username'])) {
                echo "<script>alert('Username sudah ada, silahkan ganti terlebih dahulu jika ingin registrasi');</script>";
            }

            echo "<script>alert('Registrasi gagal ditambahkan'); document.location.href = '../view/auth/register.php';</script>";
            return false;
        }
    }

    if (file_put_contents("$data_member", AddDataUser())) {
        echo "<script>alert('Registrasi berhasil'); document.location.href = '../view/auth/login.php';</script>";
    } else {
        echo "<script>alert('Registrasi gagal'); document.location.href = '../view/auth/register.php';</script>";
    }
}