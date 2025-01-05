<?php

$server = "localhost";
$username = "root";
$password = "";
$database = "kuliah_basisdata_reservasi_hotel";

$connect = new mysqli($server, $username, $password, $database);

if ($connect->connect_error) {
    die("Koneksi gagal: " . $connect->connect_error);
}
