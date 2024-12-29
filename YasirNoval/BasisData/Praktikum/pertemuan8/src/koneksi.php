<?php
$host_name = "localhost";
$db_user = "root";
$db_pass = "";
$db_name = "kuliah_basisdata_perpustakaan";

$koneksi = mysqli_connect($host_name, $db_user, $db_pass, $db_name);

if (!$koneksi) {
    die("Database not connected!");
}