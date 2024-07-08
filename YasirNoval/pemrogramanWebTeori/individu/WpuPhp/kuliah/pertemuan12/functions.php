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

function login($data)
{
    $username = htmlspecialchars($data['username']);
    $password = htmlspecialchars($data['password']);

    $query = "SELECT * FROM user WHERE username = '$username'";

    // cek dulu username
    if ($user = getData($query)) {
        // cek password
        if (password_verify($password, $user['password'])) {
            // set session
            $_SESSION['login'] = true;

            header("Location: index.php");
            exit();
        }
    }

    return [
        'error' => true,
        'pesan' => 'Username / Password Salah!'
    ];
}

function register($data)
{
    $conn = koneksi();

    $username = htmlspecialchars(strtolower($data['username']));
    $password1 = mysqli_real_escape_string($conn, $data['password1']);
    $password2 = mysqli_real_escape_string($conn, $data['password2']);

    // jika username / password kosong
    if (empty($username) || empty($password1) || empty($password2)) {
        echo "<script>alert('username / password tidak boleh kosong'); document.location.href = 'register.php';</script>";
        return false;
    }

    // jika username sudah ada
    $query = "SELECT * FROM user WHERE username = '$username'";

    if (getData($query)) {
        echo "<script>alert('username sudah terdaftar!'); document.location.href = 'register.php';</script>";
        return false;
    }

    // jika konfirmasi password tidak sesuai
    if ($password1 !== $password2) {
        echo "<script>alert('konfirmasi password tidak sesuai!'); document.location.href = 'register.php';</script>";
        return false;
    }

    // jika password < 5 digit
    if (strlen($password1) < 5) {
        echo "<script>alert('password anda terlalu pendek!'); document.location.href = 'register.php';</script>";
        return false;
    }

    // jika username dan password sudah sesuai
    // enkripsi password
    $password_baru = password_hash($password1, PASSWORD_ARGON2I);

    // insert ke tabel user
    $query = "INSERT INTO user (username, password, role) VALUES ('$username', '$password_baru', 'anggota')";

    mysqli_query($conn, $query) or die(mysqli_error($conn));

    return mysqli_affected_rows($conn);
}