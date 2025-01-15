<?php
require_once '../../config/config.php';

if (isset($_POST['submit'])) {
    $username = $_POST['username'];
    $email = $_POST['email'];
    $password = $_POST['password'];
    $confirm_password = $_POST['confirm_password'];

    // Data pelanggan
    $nama_pelanggan = $_POST['nama_pelanggan'];
    $no_hp = $_POST['no_hp'];

    // Data alamat
    $jalan = $_POST['jalan'];
    $desa = $_POST['desa'];
    $kota = $_POST['kota'];
    $provinsi = $_POST['provinsi'];
    $kode_pos = $_POST['kode_pos'];

    if ($password !== $confirm_password) {
        $error = "Password tidak cocok!";
    } else {
        try {
            $conn->beginTransaction();

            // 1. Cek username
            $stmt = $conn->prepare("SELECT id FROM users WHERE username = ?");
            $stmt->execute([$username]);

            if ($stmt->rowCount() > 0) {
                $error = "Username sudah digunakan!";
            } else {
                // 2. Insert user
                $hashed_password = password_hash($password, PASSWORD_DEFAULT);
                $stmt = $conn->prepare("INSERT INTO users (username, password, role) VALUES (?, ?, 'customer')");
                $stmt->execute([$username, $hashed_password]);
                $user_id = $conn->lastInsertId();

                // 3. Generate kode alamat
                $stmt = $conn->prepare("SELECT MAX(CAST(SUBSTRING(kode_alamat, 2) AS UNSIGNED)) as max_id FROM alamat");
                $stmt->execute();
                $result = $stmt->fetch();
                $next_id = $result['max_id'] + 1;
                $kode_alamat = 'A' . str_pad($next_id, 3, '0', STR_PAD_LEFT);

                // 4. Insert alamat
                $stmt = $conn->prepare("INSERT INTO alamat (kode_alamat, jalan, desa, kota, provinsi, kode_pos) VALUES (?, ?, ?, ?, ?, ?)");
                $stmt->execute([$kode_alamat, $jalan, $desa, $kota, $provinsi, $kode_pos]);

                // 5. Insert pelanggan
                $stmt = $conn->prepare("INSERT INTO pelanggan (nama_pelanggan, kode_alamat, no_hp, email, user_id) VALUES (?, ?, ?, ?, ?)");
                $stmt->execute([$nama_pelanggan, $kode_alamat, $no_hp, $email, $user_id]);

                $conn->commit();
                header("Location: ../login/login.php");
                exit();
            }
        } catch(PDOException $e) {
            $conn->rollBack();
            $error = "Terjadi kesalahan! Silakan coba lagi.";
        }
    }
}
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title>Registrasi - Sistem Reservasi Hotel</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet"/>
    <style>
        .login-container {
            max-width: 400px;
            margin: 100px auto;
            padding: 20px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            border-radius: 5px;
        }

        .logo {
            text-align: center;
            margin-bottom: 30px;
        }
    </style>
</head>
<body>
<div class="container">
    <div class="login-container">
        <div class="logo">
            <h2>Hotel Reservasi</h2>
        </div>
        <form action="" method="post">
            <!-- Data Users -->
            <div class="mb-3">
                <label for="username" class="form-label">Username</label>
                <input type="text" class="form-control" id="username" name="username" required/>
            </div>
            <div class="mb-3">
                <label for="email" class="form-label">Email</label>
                <input type="email" class="form-control" id="email" name="email" required/>
            </div>
            <div class="mb-3">
                <label for="password" class="form-label">Password</label>
                <input type="password" class="form-control" id="password" name="password" required/>
            </div>
            <div class="mb-3">
                <label for="confirm_password" class="form-label">Confirm Password</label>
                <input type="password" class="form-control" id="confirm_password" name="confirm_password" required/>
            </div>

            <!-- Data Pelanggan -->
            <div class="mb-3">
                <label for="nama_pelanggan" class="form-label">Nama Lengkap</label>
                <input type="text" class="form-control" id="nama_pelanggan" name="nama_pelanggan" required/>
            </div>
            <div class="mb-3">
                <label for="no_hp" class="form-label">Nomor HP</label>
                <input type="text" class="form-control" id="no_hp" name="no_hp" required/>
            </div>

            <!-- Data Alamat -->
            <div class="mb-3">
                <label for="jalan" class="form-label">Alamat</label>
                <input type="text" class="form-control" id="jalan" name="jalan" required/>
            </div>
            <div class="row mb-3">
                <div class="col">
                    <label for="desa" class="form-label">Desa</label>
                    <input type="text" class="form-control" id="desa" name="desa" required/>
                </div>
                <div class="col">
                    <label for="kota" class="form-label">Kota</label>
                    <input type="text" class="form-control" id="kota" name="kota" required/>
                </div>
            </div>
            <div class="row mb-3">
                <div class="col">
                    <label for="provinsi" class="form-label">Provinsi</label>
                    <input type="text" class="form-control" id="provinsi" name="provinsi" required/>
                </div>
                <div class="col">
                    <label for="kode_pos" class="form-label">Kode Pos</label>
                    <input type="text" class="form-control" id="kode_pos" name="kode_pos" required/>
                </div>
            </div>

            <button type="submit" name="submit" class="btn btn-primary w-100">Daftar</button>
        </form>
        <div class="text-center mt-3">
            <a href="../login/login.php">Sudah punya akun? Login</a>
        </div>
        <?php if (isset($error)): ?>
            <div class="alert alert-danger mt-3"><?php echo $error; ?></div>
        <?php endif; ?>
    </div>
</div>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
