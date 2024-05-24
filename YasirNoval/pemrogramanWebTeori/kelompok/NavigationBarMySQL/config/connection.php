<?php

// membuat koneksi ke database
$dbhost = "localhost";
$dbuser = "root";
$dbpass = "";
$dbname = "kelompok_pemweb_navigation_bar";

$connect = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);

// periksa koneksi, tampilkan pesan error jika gagal
if (!$connect) {
    die ("Koneksi ke database gagal: " . mysqli_connect_errno() . " - " . mysqli_connect_error());
}