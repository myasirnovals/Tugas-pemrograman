<?php
session_start();

require_once '../../../config/config.php';

if (!isset($_GET['id'])) {
    header('Location: pelanggan.php?status=error&message=ID Pelanggan tidak ditemukan');
    exit;
}

$id_pelanggan = $_GET['id'];

$query_pelanggan = "SELECT p.*, 
                           CONCAT(a.jalan, ', ', a.desa, ', ', a.kota, ', ', a.provinsi, ' ', a.kode_pos) as alamat_lengkap,
                           a.negara
                    FROM pelanggan p 
                    JOIN alamat a ON p.kode_alamat = a.kode_alamat 
                    WHERE p.id_pelanggan = :id";

$query_reservasi = "SELECT r.*, 
                           k.nomor_kamar, k.status as status_kamar,
                           tk.nama_tipe, tk.biaya,
                           p.id_pembayaran, p.total_bayar, p.tanggal_pembayaran,
                           mp.nama_metode as metode_pembayaran
                    FROM reservasi r
                    LEFT JOIN kamar k ON r.id_reservasi = k.id_reservasi
                    LEFT JOIN tipe_kamar tk ON k.id_tipe = tk.id_tipe
                    LEFT JOIN pembayaran p ON r.id_reservasi = p.id_reservasi
                    LEFT JOIN metode_pembayaran mp ON p.kode_mp = mp.kode_mp
                    WHERE r.id_pelanggan = :id
                    ORDER BY r.tanggal_reservasi DESC";

$stmt_pelanggan = $conn->prepare($query_pelanggan);
$stmt_pelanggan->execute(['id' => $id_pelanggan]);
$pelanggan = $stmt_pelanggan->fetch(PDO::FETCH_ASSOC);

$stmt_reservasi = $conn->prepare($query_reservasi);
$stmt_reservasi->execute(['id' => $id_pelanggan]);
$reservasi = $stmt_reservasi->fetchAll(PDO::FETCH_ASSOC);

if (!$pelanggan) {
    header('Location: pelanggan.php?status=error&message=Data pelanggan tidak ditemukan');
    exit;
}
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Detail Pelanggan - Hotel Reservation</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet">
    <link rel="stylesheet" href="pelanggan.css">
</head>
<body>
<div class="container-fluid">
    <div class="row">
        <!-- Sidebar (sama seperti di pelanggan.php) -->
        <div class="col-md-3 col-lg-2 p-0 bg-white sidebar">
            <div class="d-flex flex-column p-3">
                <h2 class="fs-4 mb-4 text-center"> Admin</h2>
                <hr>
                <ul class="nav nav-pills flex-column mb-auto">
                    <li class="nav-item mb-2">
                        <a href="../dashboard/dashboard.php" class="nav-link">
                            <i class="bi bi-speedometer2 me-2"></i>
                            Dashboard
                        </a>
                    </li>
                    <li class="nav-item mb-2">
                        <a href="pelanggan.php" class="nav-link active">
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
                <h1 class="h2">Detail Pelanggan</h1>
                <a href="pelanggan.php" class="btn btn-secondary">
                    <i class="bi bi-arrow-left"></i> Kembali
                </a>
            </div>

            <!-- Informasi Pelanggan -->
            <div class="card mb-4">
                <div class="card-header">
                    <h5 class="card-title mb-0">Informasi Pelanggan</h5>
                </div>
                <div class="card-body">
                    <table class="table table-striped">
                        <tr>
                            <th width="200">ID Pelanggan</th>
                            <td><?= htmlspecialchars($pelanggan['id_pelanggan']) ?></td>
                        </tr>
                        <tr>
                            <th>Nama</th>
                            <td><?= htmlspecialchars($pelanggan['nama_pelanggan']) ?></td>
                        </tr>
                        <tr>
                            <th>Email</th>
                            <td><?= htmlspecialchars($pelanggan['email']) ?></td>
                        </tr>
                        <tr>
                            <th>No Telepon</th>
                            <td><?= htmlspecialchars($pelanggan['no_hp']) ?></td>
                        </tr>
                        <tr>
                            <th>Alamat Lengkap</th>
                            <td><?= htmlspecialchars($pelanggan['alamat_lengkap']) ?></td>
                        </tr>
                        <tr>
                            <th>Negara</th>
                            <td><?= htmlspecialchars($pelanggan['negara']) ?></td>
                        </tr>
                    </table>
                </div>
            </div>

            <!-- Riwayat Reservasi -->
            <div class="card">
                <div class="card-header">
                    <h5 class="card-title mb-0">Riwayat Reservasi</h5>
                </div>
                <div class="card-body">
                    <?php if (empty($reservasi)): ?>
                        <p class="text-muted">Belum ada riwayat reservasi.</p>
                    <?php else: ?>
                        <div class="table-responsive">
                            <table class="table table-striped">
                                <thead>
                                <tr>
                                    <th>ID Reservasi</th>
                                    <th>Tanggal Reservasi</th>
                                    <th>Check-in</th>
                                    <th>Check-out</th>
                                    <th>Kamar</th>
                                    <th>Tipe Kamar</th>
                                    <th>Status</th>
                                    <th>Pembayaran</th>
                                </tr>
                                </thead>
                                <tbody>
                                <?php foreach ($reservasi as $r): ?>
                                    <tr>
                                        <td><?= htmlspecialchars($r['id_reservasi']) ?></td>
                                        <td><?= htmlspecialchars($r['tanggal_reservasi']) ?></td>
                                        <td><?= htmlspecialchars($r['tanggal_checkin']) ?></td>
                                        <td><?= htmlspecialchars($r['tanggal_checkout']) ?></td>
                                        <td><?= htmlspecialchars($r['nomor_kamar'] ?? '-') ?></td>
                                        <td><?= htmlspecialchars($r['nama_tipe'] ?? '-') ?></td>
                                        <td>
                                                <span class="badge bg-<?= $r['status'] == 'Confirmed' ? 'success' :
                                                    ($r['status'] == 'Pending' ? 'warning' : 'danger') ?>">
                                                    <?= htmlspecialchars($r['status']) ?>
                                                </span>
                                        </td>
                                        <td>
                                            <?php if (isset($r['id_pembayaran'])): ?>
                                                <small>
                                                    ID: <?= htmlspecialchars($r['id_pembayaran']) ?><br>
                                                    Total: Rp <?= number_format($r['total_bayar'], 0, ',', '.') ?><br>
                                                    Metode: <?= htmlspecialchars($r['metode_pembayaran']) ?><br>
                                                    Tanggal: <?= htmlspecialchars($r['tanggal_pembayaran']) ?>
                                                </small>
                                            <?php else: ?>
                                                <span class="text-muted">Belum ada pembayaran</span>
                                            <?php endif; ?>
                                        </td>
                                    </tr>
                                <?php endforeach; ?>
                                </tbody>
                            </table>
                        </div>
                    <?php endif; ?>
                </div>
            </div>
        </div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
