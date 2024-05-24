<?php

function getConnection(): PDO
{
    $host = 'localhost';
    $port = 3306;
    $database = "kelompok_pemweb_webpage";
    $username = "root";
    $password = "";

    return new PDO("mysql:host=$host:$port;dbname=$database", $username, $password);
}

try {
    getConnection();
} catch (Exception $exception) {
    echo "<script>alert('Error Tidak Terkoneksi ke Database')</script>";
    return $exception->getMessage();
}