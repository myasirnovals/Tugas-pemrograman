<?php
session_start();

if (!isset($_SESSION['user_id']) || !isset($_SESSION['role']) || $_SESSION['role'] !== 'admin') {
    header("Location: ../../../index.php");
    exit();
}

require_once '../../../config/config.php';

if (!isset($_GET['id'])) {
    header('Location: reservasi.php?status=error&message=ID tidak valid');
    exit;
}

$id_reservasi = $_GET['id'];

$query = "SELECT r.*, p.nama_pelanggan 
          FROM reservasi r 
          JOIN pelanggan p ON r.id_pelanggan = p.id_pelanggan 
          WHERE r.id_reservasi = :id";
$stmt = $conn->prepare($query);
$stmt->execute(['id' => $id_reservasi]);
$reservasi = $stmt->fetch(PDO::FETCH_ASSOC);

if (!$reservasi) {
    header('Location: reservasi.php?status=error&message=Data tidak ditemukan');
    exit;
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        $query = "UPDATE reservasi SET 
                  tanggal_checkin = :check_in,
                  tanggal_checkout = :check_out,
                  status = :status
                  WHERE id_reservasi = :id";

        $stmt = $conn->prepare($query);
        $stmt->execute([
            'check_in' => $_POST['check_in'],
            'check_out' => $_POST['check_out'],
            'status' => $_POST['status'],
            'id' => $id_reservasi
        ]);

        header('Location: reservasi.php?status=success&message=Data berhasil diupdate');
        exit;
    } catch (PDOException $e) {
        header('Location: reservasi.php?status=error&message=Gagal mengupdate data: ' . $e->getMessage());
        exit;
    }
}
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Update Reservasi - Hotel Reservation</title>
    <!-- Bootstrap 5.3.2 CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
    <!-- Bootstrap Icons -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet">
    <link rel="stylesheet" href="reservasi.css">
</head>
<body>
<div class="container-fluid">
    <div class="row">
        <!-- Sidebar sama seperti reservasi.php -->
        <div class="col-md-3 col-lg-2 p-0 bg-white sidebar">
            <div class="d-flex flex-column p-3">
                <h2 class="fs-4 mb-4 text-center">Admin</h2>
                <hr />
                <ul class="nav nav-pills flex-column mb-auto">
                    <li class="nav-item mb-2">
                        <a href="../dashboard/dashboard.php" class="nav-link">
                            <i class="bi bi-speedometer2 me-2"></i>
                            Dashboard
                        </a>
                    </li>
                    <li class="nav-item mb-2">
                        <a href="../pelanggan/pelanggan.php" class="nav-link">
                            <i class="bi bi-people me-2"></i>
                            Pelanggan
                        </a>
                    </li>
                    <li class="nav-item mb-2">
                        <a href="reservasi.php" class="nav-link active">
                            <i class="bi bi-calendar-check me-2"></i>
                            Reservasi
                        </a>
                    </li>
                    <li class="nav-item mb-2">
                        <a href="../kamar/kamar.php" class="nav-link">
                            <i class="bi bi-house-door me-2"></i>
                            Kamar
                        </a>
                    </li>
                    <li class="nav-item mb-2">
                        <a href="../pembayaran/pembayaran.php" class="nav-link">
                            <i class="bi bi-credit-card me-2"></i>
                            Pembayaran
                        </a>
                    </li>
                </ul>
                <hr/>
                <a href="../../login/logout.php" class="btn btn-danger">
                    <i class="bi bi-box-arrow-right me-2"></i>
                    Logout
                </a>
            </div>
        </div>

        <!-- Main Content -->
        <div class="col-md-9 col-lg-10 content">
            <div class="d-flex justify-content-between align-items-center mb-4">
                <h1 class="h2">Update Reservasi</h1>
            </div>

            <div class="card">
                <div class="card-body">
                    <form action="" method="POST">
                        <div class="mb-3">
                            <label class="form-label">ID Reservasi</label>
                            <input type="text" class="form-control" value="<?= htmlspecialchars($reservasi['id_reservasi']) ?>" disabled>
                        </div>
                        <div class="mb-3">
                            <label class="form-label">Nama Pelanggan</label>
                            <input type="text" class="form-control" value="<?= htmlspecialchars($reservasi['nama_pelanggan']) ?>" disabled>
                        </div>
                        <div class="mb-3">
                            <label class="form-label">Check In</label>
                            <input type="date" name="check_in" class="form-control" value="<?= htmlspecialchars($reservasi['tanggal_checkin']) ?>" required>
                        </div>
                        <div class="mb-3">
                            <label class="form-label">Check Out</label>
                            <input type="date" name="check_out" class="form-control" value="<?= htmlspecialchars($reservasi['tanggal_checkout']) ?>" required>
                        </div>
                        <div class="mb-3">
                            <label class="form-label">Status</label>
                            <select name="status" class="form-select" required>
                                <option value="Confirmed" <?= $reservasi['status'] == 'Confirmed' ? 'selected' : '' ?>>Confirmed</option>
                                <option value="Pending" <?= $reservasi['status'] == 'Pending' ? 'selected' : '' ?>>Pending</option>
                                <option value="Cancelled" <?= $reservasi['status'] == 'Cancelled' ? 'selected' : '' ?>>Cancelled</option>
                            </select>
                        </div>
                        <div class="d-flex justify-content-between">
                            <a href="reservasi.php" class="btn btn-secondary">Kembali</a>
                            <button type="submit" class="btn btn-primary">Update Reservasi</button>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Bootstrap Bundle JS -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
