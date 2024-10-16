<!DOCTYPE html>
<html data-bs-theme="light" lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
    <title>Login</title>
    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="../../assets/bootstrap/css/bootstrap.min.css">

    <!-- CSS -->
    <link rel="stylesheet" href="../../assets/css/Features-Image-images.css">
    <link rel="stylesheet" href="../../assets/css/Footer-Basic-icons.css">
    <link rel="stylesheet" href="../../assets/css/Bootstrap-Payment-Form.css">
    <link rel="stylesheet" href="../../assets/css/CheckOutPage-V10.css">
    <link rel="stylesheet" href="../../assets/css/Ludens-Users---4-Edit-Profile.css">
    <link rel="stylesheet" href="../../assets/css/Profile-Edit-Form-styles.css">
    <link rel="stylesheet" href="../../assets/css/Profile-Edit-Form.css">
    <link rel="stylesheet" href="../../assets/css/kasir.css">

    <!-- jQuery -->
    <script src="../../assets/bootstrap/js/jquery-3.7.1.min.js"></script>
</head>
<body>
<section class="position-relative py-4 py-xl-5">
    <div class="container">
        <div class="row mb-5">
            <div class="col-md-8 col-xl-6 text-center mx-auto">
                <h2 style="color: var(--green);">Login</h2>
            </div>
        </div>
        <div class="row d-flex justify-content-center">
            <div class="col-md-6 col-xl-4">
                <div class="card mb-5 text-white kartu">
                    <div class="card-body d-flex flex-column align-items-center">
                        <form action="../../routes/user_login.php" method="post">
                            <div class="mb-3">
                                <label for="username" class="form-label">Username:</label>
                                <input type="text" name="username" id="username" class="form-control" required>
                            </div>
                            <div class="mb-3">
                                <label for="password" class="form-label">Password:</label>
                                <input type="password" name="password" id="password" class="form-control"
                                       required>
                            </div>
                            <div class="mb-3">
                                <button class="btn btn-primary d-block w-100" type="submit" name="login">Login</button>
                            </div>
                            <span class="text-white">Belum jadi member?</span>
                            <a href="register.php" class="text-decoration-none">Register now</a>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>
<script src="../../assets/bootstrap/js/bootstrap.min.js"></script>
</body>
</html>
