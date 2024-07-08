<?php
session_start();

if (isset($_SESSION['login'])) {
    header("Location: index.php");
    exit();
}

require_once __DIR__ . '/functions.php';

// ketika tombol login di tekan
if (isset($_POST['login'])) {
    $login = login($_POST);
}
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Login</title>

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="css/bootstrap.min.css">
</head>
<body>
<div class="container-fluid">
    <div class="container mt-5 mb-5">
        <div class="row justify-content-center">
            <h3 class="text-center">Form Login</h3>
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
                            <label for="password" class="form-label">Password: </label>
                            <input class="form-control" type="password" name="password" id="password" required>
                        </div>
                        <button class="btn btn-primary mt-4 w-100" type="submit" name="login">Login</button>
                    </form>
                    <br>
                    <p>Belum punya akun? <br><a href="register.php">Registrasi Sekarang</a></p>
                </div>
            </div>
        </div>
    </div>
</div>


<!-- Bootstrap JS -->
<script src="js/bootstrap.min.js"></script>
</body>
</html>