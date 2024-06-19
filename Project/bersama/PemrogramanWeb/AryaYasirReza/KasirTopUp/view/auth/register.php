<!DOCTYPE html>
<html data-bs-theme="light" lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
    <title>Register</title>
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
                <h2 style="color: var(--green);">Daftar Member</h2>
            </div>
        </div>
        <div class="row d-flex justify-content-center">
            <div class="col-md-6 col-xl-4">
                <div class="card mb-5 text-white kartu">
                    <div class="card-body d-flex flex-column align-items-center">
                        <form action="../../routes/user_register.php" method="post">
                            <div class="row">
                                <div class="col-6 col-sm-12">
                                    <div class="mb-3">
                                        <label for="name" class="form-label">Nama:</label>
                                        <input type="text" name="name" id="name" class="form-control"
                                               pattern="[a-z A-Z]+" required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="email" class="form-label">Email:</label>
                                        <input type="email" name="email" id="email" class="form-control" required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="username" class="form-label">Username:</label>
                                        <input type="text" name="username" id="username" class="form-control" required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="password" class="form-label">Password:</label>
                                        <input type="password" name="password" id="password" class="form-control"
                                               required>
                                    </div>
                                </div>
                                <div class="col-6 col-sm-12">
                                    <div class="mb-3">
                                        <label for="phone" class="form-label">Nomor telepon:</label>
                                        <input type="text" name="phone" id="phone" class="form-control"
                                               pattern="[0-9]+" required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="members" class="form-label">Member Group:</label>
                                        <select name="members" id="members" class="form-control">
                                            <option value="silver">Silver</option>
                                            <option value="gold">Gold</option>
                                            <option value="platinum">Platinum</option>
                                        </select>
                                    </div>
                                </div>
                            </div>
                            <div class="mb-3">
                                <button type="submit" class="btn btn-primary d-block w-100 mt-4 mb-4">Register</button>
                            </div>
                            <span class="text-white">Sudah jadi member?</span>
                            <a href="login.php" class="text-decoration-none">Login now</a>
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
