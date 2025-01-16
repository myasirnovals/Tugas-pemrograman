<?php
session_start();
require_once '../../config/config.php';

if (isset($_POST['submit'])) {
    $username = $_POST['username'];
    $email = $_POST['email'];

    $stmt = $conn->prepare("SELECT p.*, u.id as user_id 
                           FROM pelanggan p 
                           JOIN users u ON p.user_id = u.id 
                           WHERE u.username = ? AND p.email = ?");
    $stmt->execute([$username, $email]);
    $user = $stmt->fetch();

    if ($user) {
        $_SESSION['reset_user_id'] = $user['user_id'];
        header("Location: reset-password.php");
        exit();
    } else {
        $error = "Username atau email tidak ditemukan!";
    }
}
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title>Lupa Password - Sistem Reservasi Hotel</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet"/>
    <style>
        .login-container {
            max-width: 400px;
            margin: 100px auto;
            padding: 20px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            border-radius: 5px;
        }
    </style>
</head>
<body>
<div class="container">
    <div class="login-container">
        <h3 class="text-center mb-4">Lupa Password</h3>

        <?php if (isset($error)): ?>
            <div class="alert alert-danger alert-dismissible fade show" role="alert">
                <?php echo $error; ?>
                <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
            </div>
        <?php endif; ?>

        <form action="" method="post">
            <div class="mb-3">
                <label for="username" class="form-label">Username</label>
                <input type="text" class="form-control" id="username" name="username"
                       required placeholder="Masukkan username"/>
            </div>
            <div class="mb-3">
                <label for="email" class="form-label">Email</label>
                <input type="email" class="form-control" id="email" name="email"
                       required placeholder="Masukkan email terdaftar"/>
            </div>
            <button type="submit" name="submit" class="btn btn-primary w-100 mb-3">
                Reset Password
            </button>
            <div class="text-center">
                <a href="login.php" class="text-decoration-none">Kembali ke Login</a>
            </div>
        </form>
    </div>
</div>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
