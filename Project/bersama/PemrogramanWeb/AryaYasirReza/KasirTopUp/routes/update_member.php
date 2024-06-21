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
        if (($row['phone'] == $_POST['phone']) || ($row['username'] == $_POST['username'])) {
            if(($row['phone'] == $_POST['phone'])) {
                echo "<script>alert('Nomor Telepon sudah digunakan, silahkan ganti dengan nomor yang lain');</script>";
            } elseif (($row['username'] == $_POST['username'])) {
                echo "<script>alert('Username sudah digunakan, silahkan ganti dengan username yang lain');</script>";
            }

            echo "<script>alert('Member gagal di update'); document.location.href = '../view/admin/update_member.php';</script>";
            return false;
        }
    }

    if (file_put_contents($data_member, UpdateMember())) {
        echo "<script>alert('Member berhasil di update'); document.location.href = '../view/admin/member.php';</script>";
    } else {
        echo "<script>alert('Member gagal di update'); document.location.href = '../view/admin/member.php';</script>";
    }
}