<?php
include "../app/GetData.php";

if (isset($_POST["login"])) {
    $username = $_POST['username'];

    $data_member = "../database/data_member" . ".json";

    $my_data = file_get_contents("$data_member");
    $array_data = json_decode($my_data, true);

    foreach ($array_data as $array) {
        if (($array["username"] == $username) && password_verify($_POST["password"], $array['password'])) {
            session_start();

            $_SESSION['logged'] = TRUE;
            $_SESSION['memberId'] = $array['memberId'];
            $_SESSION['username'] = $username;
            $_SESSION['email'] = $array['email'];
            $_SESSION['name'] = $array['name'];

            if ($array['members'] == 'admin') {
                echo "<script>document.location.href = '../view/admin/home.php';</script>";
            } else {
                echo "<script>document.location.href = '../view/user/user.php';</script>";
            }
        }
    }
    echo "<script>alert('login gagal'); document.location.href = '../view/auth/login.php';</script>";
}