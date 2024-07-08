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

    mysqli_query($conn, $query) or die(mysqli_error($conn));


    return mysqli_affected_rows($conn);
}

function hapus($id)
{
    $conn = koneksi();

    mysqli_query($conn, "DELETE FROM mahasiswa WHERE id = $id") or die(mysqli_error($conn));

    return mysqli_affected_rows($conn);
}

function ubah($data)
{
    $conn = koneksi();

    $id = $data['id'];
    $nama = htmlspecialchars($data['nama']);
    $nim = htmlspecialchars($data['nim']);
    $email = htmlspecialchars($data['email']);
    $club = htmlspecialchars($data['club']);
    $gambar = htmlspecialchars($data['gambar']);

    $query = "
        UPDATE mahasiswa
        SET nama   = '$nama',
            nim    = '$nim',
            email  = '$email',
            club   = '$club',
            gambar = '$gambar'
        WHERE id = $id";

    mysqli_query($conn, $query) or die(mysqli_error($conn));


    return mysqli_affected_rows($conn);
}

function cari($keyword)
{
    $query = "SELECT * FROM mahasiswa WHERE nama LIKE '%$keyword%' OR nim LIKE '%$keyword%'";

    return getAllData($query);
}