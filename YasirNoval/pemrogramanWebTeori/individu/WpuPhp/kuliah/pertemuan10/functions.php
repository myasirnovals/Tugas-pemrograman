<?php

function koneksi()
{
    return mysqli_connect('localhost', 'root', '', 'kuliah_php_wpu_datamhs');
}

/**
 * @param $query
 * @return array
 *
 * fungsi ini digunakan untuk mengambil 1 data
 * dari tabel yang terdapat di database
 */
function getData($query)
{
    $conn = koneksi();
    $result = mysqli_query($conn, $query);

    $rows = [];
    while ($row = mysqli_fetch_assoc($result)) {
        $rows = $row;
    }

    return $rows;
}


/**
 * @param $query
 * @return bool|mysqli_result
 *
 * fungsi ini digunakan untuk mengambil seluruh
 * data dari tabel yang terdapat di database,
 *
 * catatam:
 * gunakan foreach untuk mengambil setiap datanya
 */
function getAllData($query)
{
    $conn = koneksi();

    return mysqli_query($conn, $query);
}

function tambah($data)
{
    $conn = koneksi();

    $nama = htmlspecialchars($data['nama']);
    $nim = htmlspecialchars($data['nim']);
    $email = htmlspecialchars($data['email']);
    $club = htmlspecialchars($data['club']);
    $gambar = htmlspecialchars($data['gambar']);

    $query = "INSERT INTO mahasiswa (nim, nama, email, club, gambar) VALUES ('$nim', '$nama', '$email', '$club', '$gambar')";

    mysqli_query($conn, $query);

    echo mysqli_error($conn);

    return mysqli_affected_rows($conn);
}