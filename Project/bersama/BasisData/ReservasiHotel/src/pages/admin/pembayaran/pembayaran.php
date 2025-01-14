<?php
require_once '../../../config/config.php';

// Query untuk mengambil data pembayaran dengan join ke tabel terkait
$query = "SELECT p.id_pembayaran, p.id_reservasi, p.tanggal_pembayaran, 
          mp.nama_metode, p.total_bayar,
          CASE 
            WHEN r.status = 'Confirmed' THEN 'Lunas'
            WHEN r.status = 'Pending' THEN 'Pending'
            WHEN r.status = 'Cancelled' THEN 'Gagal'
          END as status
          FROM pembayaran p
          JOIN metode_pembayaran mp ON p.kode_mp = mp.kode_mp
          JOIN reservasi r ON p.id_reservasi = r.id_reservasi
          ORDER BY p.tanggal_pembayaran DESC";

$stmt = $conn->prepare($query);
$stmt->execute();
$pembayarans = $stmt->fetchAll(PDO::FETCH_ASSOC);

// Query untuk mendapatkan statistik
$queryStats = "SELECT 
    COUNT(*) as total_hari_ini,
    SUM(CASE WHEN r.status = 'Confirmed' THEN 1 ELSE 0 END) as total_lunas,
    SUM(CASE WHEN r.status = 'Pending' THEN 1 ELSE 0 END) as total_pending,
    SUM(CASE WHEN r.status = 'Cancelled' THEN 1 ELSE 0 END) as total_gagal
    FROM pembayaran p
    JOIN reservasi r ON p.id_reservasi = r.id_reservasi
    WHERE DATE(p.tanggal_pembayaran) = CURDATE()";

$stmtStats = $conn->prepare($queryStats);
$stmtStats->execute();
$stats = $stmtStats->fetch(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Pembayaran - Hotel Reservation</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" />
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet" />
    <link rel="stylesheet" href="pembayaran.css" />
</head>
<body>
<div class="container-fluid">
    <div class="row">
        <!-- Sidebar -->
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
                <a href="pembayaran.php" class="nav-link active">
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
                <h1 class="h2">Data Pembayaran</h1>
                <button class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#addPembayaranModal">
                    <i class="bi bi-plus-circle me-2"></i>Tambah Pembayaran
                </button>
            </div>

            <!-- Summary Cards -->
            <div class="row mb-4">
                <div class="col-md-3">
                    <div class="card payment-card bg-primary text-white">
                        <div class="card-body">
                            <h6 class="card-title">Total Pembayaran Hari Ini</h6>
                            <h3 class="mb-0"><?= $stats['total_hari_ini'] ?></h3>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="card payment-card bg-success text-white">
                        <div class="card-body">
                            <h6 class="card-title">Pembayaran Lunas</h6>
                            <h3 class="mb-0"><?= $stats['total_lunas'] ?></h3>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="card payment-card bg-warning text-white">
                        <div class="card-body">
                            <h6 class="card-title">Menunggu Pembayaran</h6>
                            <h3 class="mb-0"><?= $stats['total_pending'] ?></h3>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="card payment-card bg-danger text-white">
                        <div class="card-body">
                            <h6 class="card-title">Pembayaran Gagal</h6>
                            <h3 class="mb-0"><?= $stats['total_gagal'] ?></h3>
                        </div>
                    </div>
                </div>
            </div>

            <!-- Pembayaran Table -->
            <div class="card">
                <div class="card-body">
                    <div class="table-responsive">
                        <table class="table table-hover">
                            <thead>
                            <tr>
                                <th>ID Pembayaran</th>
                                <th>ID Reservasi</th>
                                <th>Tanggal Pembayaran</th>
                                <th>Metode</th>
                                <th>Total Bayar</th>
                                <th>Status</th>
                                <th>Aksi</th>
                            </tr>
                            </thead>
                            <tbody>
                            <?php foreach ($pembayarans as $pembayaran): ?>
                                <tr>
                                    <td><?= $pembayaran['id_pembayaran'] ?></td>
                                    <td><?= $pembayaran['id_reservasi'] ?></td>
                                    <td><?= $pembayaran['tanggal_pembayaran'] ?></td>
                                    <td><?= $pembayaran['nama_metode'] ?></td>
                                    <td>Rp <?= number_format($pembayaran['total_bayar'], 0, ',', '.') ?></td>
                                    <td>
                                            <span class="badge bg-<?=
                                            $pembayaran['status'] == 'Lunas' ? 'success' :
                                                ($pembayaran['status'] == 'Pending' ? 'warning' : 'danger')
                                            ?>">
                                                <?= $pembayaran['status'] ?>
                                            </span>
                                    </td>
                                    <td>
                                        <button class="btn btn-sm btn-primary" title="Lihat Detail">
                                            <i class="bi bi-eye"></i>
                                        </button>
                                        <button class="btn btn-sm btn-warning" title="Edit">
                                            <i class="bi bi-pencil"></i>
                                        </button>
                                        <button class="btn btn-sm btn-danger" title="Hapus">
                                            <i class="bi bi-trash"></i>
                                        </button>
                                    </td>
                                </tr>
                            <?php endforeach; ?>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
