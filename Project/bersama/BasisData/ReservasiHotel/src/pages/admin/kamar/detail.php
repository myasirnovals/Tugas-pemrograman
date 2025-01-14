<?php
require_once '../../../config/config.php';

if (!isset($_GET['id']) || empty($_GET['id'])) {
    header('Location: kamar.php?status=error&message=ID Kamar tidak valid');
    exit;
}

$id_kamar = trim($_GET['id']);

try {
    $query = "SELECT k.*, tk.nama_tipe, tk.biaya, f.nama_fasilitas 
              FROM kamar k
              JOIN tipe_kamar tk ON k.id_tipe = tk.id_tipe
              JOIN fasilitas f ON tk.kode_fasilitas = f.kode_fasilitas
              WHERE k.id_kamar = :id_kamar";

    $stmt = $conn->prepare($query);
    $stmt->execute(['id_kamar' => $id_kamar]);
    $kamar = $stmt->fetch(PDO::FETCH_ASSOC);

    if (!$kamar) {
        throw new Exception("Data kamar tidak ditemukan");
    }

} catch (Exception $e) {
    header('Location: kamar.php?status=error&message=' . urlencode($e->getMessage()));
    exit;
}

function formatRupiah($angka) {
    return 'Rp ' . number_format($angka, 0, ',', '.');
}

function getStatusBadge($status) {
    switch(strtolower($status)) {
        case 'available':
            return '<span class="badge bg-success">Available</span>';
        case 'occupied':
            return '<span class="badge bg-danger">Occupied</span>';
        case 'reserved':
            return '<span class="badge bg-warning">Reserved</span>';
        default:
            return '<span class="badge bg-secondary">'.$status.'</span>';
    }
}
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Detail Kamar - Hotel Reservation</title>
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
    <!-- Bootstrap Icons -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet">
    <link rel="stylesheet" href="kamar.css">
</head>
<body>
<div class="container-fluid">
    <div class="row">
        <!-- Sidebar (sama seperti di kamar.php) -->
        <div class="col-md-3 col-lg-2 p-0 bg-white sidebar">
            <div class="d-flex flex-column p-3">
                <h2 class="fs-4 mb-4 text-center">Admin</h2>
                <hr/>
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
                        <a href="../reservasi/reservasi.php" class="nav-link">
                            <i class="bi bi-calendar-check me-2"></i>
                            Reservasi
                        </a>
                    </li>
                    <li class="nav-item mb-2">
                        <a href="kamar.php" class="nav-link active">
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
            </div>
        </div>

        <!-- Main Content -->
        <div class="col-md-9 col-lg-10 content">
            <div class="d-flex justify-content-between align-items-center mb-4">
                <h1 class="h2">Detail Kamar</h1>
                <a href="kamar.php" class="btn btn-secondary">
                    <i class="bi bi-arrow-left me-2"></i>Kembali
                </a>
            </div>

            <div class="card">
                <div class="card-body">
                    <div class="row">
                        <div class="col-md-6">
                            <h3 class="card-title mb-4">Informasi Kamar</h3>
                            <table class="table table-borderless">
                                <tr>
                                    <th width="200">Nomor Kamar</th>
                                    <td><?= htmlspecialchars($kamar['nomor_kamar']) ?></td>
                                </tr>
                                <tr>
                                    <th>Tipe Kamar</th>
                                    <td><?= htmlspecialchars($kamar['nama_tipe']) ?></td>
                                </tr>
                                <tr>
                                    <th>Status</th>
                                    <td><?= getStatusBadge($kamar['status']) ?></td>
                                </tr>
                                <tr>
                                    <th>Biaya per Malam</th>
                                    <td><?= formatRupiah($kamar['biaya']) ?></td>
                                </tr>
                            </table>
                        </div>
                        <div class="col-md-6">
                            <h3 class="card-title mb-4">Fasilitas</h3>
                            <div class="d-flex align-items-center mb-3">
                                <i class="bi bi-check-circle-fill text-success me-2"></i>
                                <span><?= htmlspecialchars($kamar['nama_fasilitas']) ?></span>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Bootstrap JS -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
