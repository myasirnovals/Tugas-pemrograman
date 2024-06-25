<?php
require_once __DIR__ . '/functions.php';

// ketika tombol register di tekan
if (isset($_POST['register'])) {
    if (register($_POST) > 0) {
        echo "<script>alert('user baru berhasil ditmbahkan. silahkan login!'); document.location.href = 'login.php';</script>";
        return false;
    } else {
        echo "user gagal ditambahkan!";
    }
}
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Registrasi</title>

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="css/bootstrap.min.css">
</head>
<body>
<div class="container-fluid">
    <div class="container mt-5 mb-5">
        <div class="row justify-content-center">
            <h3 class="text-center">Form Registrasi</h3>
            <?php if (isset($login['error'])) { ?>
                <p class="text-center text-danger mt-5"><?= $login['pesan']; ?></p>
            <?php } ?>
            <div class="card mt-4 w-25">
                <div class="card-body ">
                    <form action="" method="post">
                        <div class="form-group">
                            <label for="username" class="form-label">Username: </label>
                            <input class="form-control" type="text" name="username" id="username" autocomplete="off"
                                   autofocus required>
                        </div>
                        <div class="form-group">
                            <label for="password1" class="form-label">Password: </label>
                            <input class="form-control" type="password" name="password1" id="password1" required>
                        </div>
                        <div class="form-group">
                            <label for="password2" class="form-label">Konfirmasi Password: </label>
                            <input class="form-control" type="password" name="password2" id="password2" required>
                        </div>
                        <button class="btn btn-primary mt-4 w-100" type="submit" name="register">Register</button>
                    </form>
                    <br>
                    <p>Sudah punya akun? <br><a href="login.php">Login Sekarang</a></p>
                </div>
            </div>
        </div>
    </div>
</div>


<!-- Bootstrap JS -->
<script src="js/bootstrap.min.js"></script>
</body>
</html>