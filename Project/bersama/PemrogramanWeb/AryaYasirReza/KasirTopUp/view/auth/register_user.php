<?php
include "../../app/AddData.php";

if (isset($_POST['register'])) {
    // data exist
    $address = "-";
    $birthdate = "-";
    $created_at = date('l, d / M / Y  H:i:s');
    $updated_at = date('l, d / M / Y  H:i:s');

    // filter data
    $name = filter_input(INPUT_POST, 'name', FILTER_SANITIZE_STRING);
    $username = filter_input(INPUT_POST, 'username', FILTER_SANITIZE_STRING);
    $members = filter_input(INPUT_POST, 'members', FILTER_SANITIZE_STRING);
    $telp = filter_input(INPUT_POST, 'telp', FILTER_SANITIZE_NUMBER_INT);

    // verify telephone
    if ($telp == null || ) {
        echo "Data yang anda masukan bukan nomor telephone";
        return false;
    }

    // verify email
    $email = filter_input(INPUT_POST, 'email', FILTER_VALIDATE_EMAIL);

    // encryption password
    $password = password_hash($_POST['password'], PASSWORD_BCRYPT);

    // save data on file json
    $data_member = "../../database/data_member" . ".json";

    if (file_put_contents("$data_member", AddDataUser(
        $name, $address, $birthdate, $username, $email, $password, $members, $telp, $created_at, $updated_at
    ))) {
        echo "<script>alert('Registrasi anda berhasil ditambahkan'); document.location.href = '../login.php';</script>";
    } else {
        echo "<script>alert('Registrasi anda gagal ditambahkan'); document.location.href = '../login.php';</script>";
    }
}