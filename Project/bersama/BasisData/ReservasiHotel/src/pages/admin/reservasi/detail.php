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

$query = "SELECT 
            r.id_reservasi,
            r.tanggal_reservasi,
            r.tanggal_checkin,
            r.tanggal_checkout,
            r.status as status_reservasi,
            p.nama_pelanggan,
            p.no_hp,
            p.email,
            k.nomor_kamar,
            k.status as status_kamar,
            tk.nama_tipe,
            tk.biaya,
            a.jalan,
            a.desa,
            a.kota,
            a.provinsi,
            pb.total_bayar,
            pb.tanggal_pembayaran,
            mp.nama_metode,
            f.nama_fasilitas
          FROM reservasi r
          JOIN pelanggan p ON r.id_pelanggan = p.id_pelanggan
          JOIN alamat a ON p.kode_alamat = a.kode_alamat
          JOIN kamar k ON k.id_reservasi = r.id_reservasi
          JOIN tipe_kamar tk ON k.id_tipe = tk.id_tipe
          JOIN fasilitas f ON tk.kode_fasilitas = f.kode_fasilitas
          LEFT JOIN pembayaran pb ON pb.id_reservasi = r.id_reservasi
          LEFT JOIN metode_pembayaran mp ON pb.kode_mp = mp.kode_mp
          WHERE r.id_reservasi = :id";

$stmt = $conn->prepare($query);
$stmt->execute(['id' => $id_reservasi]);
$detail = $stmt->fetch(PDO::FETCH_ASSOC);

if (!$detail) {
    header('Location: reservasi.php?status=error&message=Data tidak ditemukan');
    exit;
}
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Detail Reservasi - Hotel Reservation</title>
    <!-- Bootstrap 5.3.2 CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
    <!-- Bootstrap Icons -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet">
    <link rel="stylesheet" href="reservasi.css">
</head>
<body>
<div class="container-fluid">
    <div class="row">
        <!-- Sidebar -->
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
                <h1 class="h2">Detail Reservasi</h1>
                <a href="reservasi.php" class="btn btn-secondary">
                    <i class="bi bi-arrow-left me-2"></i>Kembali
                </a>
            </div>

            <div class="row">
                <!-- Informasi Reservasi -->
                <div class="col-md-6 mb-4">
                    <div class="card">
                        <div class="card-header">
                            <h5 class="card-title mb-0">Informasi Reservasi</h5>
                        </div>
                        <div class="card-body">
                            <table class="table table-borderless">
                                <tr>
                                    <th width="40%">ID Reservasi</th>
                                    <td><?= htmlspecialchars($detail['id_reservasi']) ?></td>
                                </tr>
                                <tr>
                                    <th>Tanggal Reservasi</th>
                                    <td><?= htmlspecialchars($detail['tanggal_reservasi']) ?></td>
                                </tr>
                                <tr>
                                    <th>Check In</th>
                                    <td><?= htmlspecialchars($detail['tanggal_checkin']) ?></td>
                                </tr>
                                <tr>
                                    <th>Check Out</th>
                                    <td><?= htmlspecialchars($detail['tanggal_checkout']) ?></td>
                                </tr>
                                <tr>
                                    <th>Status</th>
                                    <td>
                                        <?php
                                        $statusClass = [
                                            'Confirmed' => 'success',
                                            'Pending' => 'warning',
                                            'Cancelled' => 'danger'
                                        ];
                                        $class = $statusClass[$detail['status_reservasi']] ?? 'secondary';
                                        ?>
                                        <span class="badge bg-<?= $class ?>">
                                                <?= htmlspecialchars($detail['status_reservasi']) ?>
                                            </span>
                                    </td>
                                </tr>
                            </table>
                        </div>
                    </div>
                </div>

                <!-- Informasi Pelanggan -->
                <div class="col-md-6 mb-4">
                    <div class="card">
                        <div class="card-header">
                            <h5 class="card-title mb-0">Informasi Pelanggan</h5>
                        </div>
                        <div class="card-body">
                            <table class="table table-borderless">
                                <tr>
                                    <th width="40%">Nama</th>
                                    <td><?= htmlspecialchars($detail['nama_pelanggan']) ?></td>
                                </tr>
                                <tr>
                                    <th>No. HP</th>
                                    <td><?= htmlspecialchars($detail['no_hp']) ?></td>
                                </tr>
                                <tr>
                                    <th>Email</th>
                                    <td><?= htmlspecialchars($detail['email']) ?></td>
                                </tr>
                                <tr>
                                    <th>Alamat</th>
                                    <td>
                                        <?= htmlspecialchars($detail['jalan']) ?><br>
                                        <?= htmlspecialchars($detail['desa']) ?>,
                                        <?= htmlspecialchars($detail['kota']) ?><br>
                                        <?= htmlspecialchars($detail['provinsi']) ?>
                                    </td>
                                </tr>
                            </table>
                        </div>
                    </div>
                </div>

                <!-- Informasi Kamar -->
                <div class="col-md-6 mb-4">
                    <div class="card">
                        <div class="card-header">
                            <h5 class="card-title mb-0">Informasi Kamar</h5>
                        </div>
                        <div class="card-body">
                            <table class="table table-borderless">
                                <tr>
                                    <th width="40%">Nomor Kamar</th>
                                    <td><?= htmlspecialchars($detail['nomor_kamar']) ?></td>
                                </tr>
                                <tr>
                                    <th>Tipe Kamar</th>
                                    <td><?= htmlspecialchars($detail['nama_tipe']) ?></td>
                                </tr>
                                <tr>
                                    <th>Fasilitas</th>
                                    <td><?= htmlspecialchars($detail['nama_fasilitas']) ?></td>
                                </tr>
                                <tr>
                                    <th>Biaya per Malam</th>
                                    <td>Rp <?= number_format($detail['biaya'], 0, ',', '.') ?></td>
                                </tr>
                                <tr>
                                    <th>Status Kamar</th>
                                    <td>
                                        <?php
                                        $statusClass = [
                                            'Available' => 'success',
                                            'Occupied' => 'danger',
                                            'Reserved' => 'warning'
                                        ];
                                        $class = $statusClass[$detail['status_kamar']] ?? 'secondary';
                                        ?>
                                        <span class="badge bg-<?= $class ?>">
                                                <?= htmlspecialchars($detail['status_kamar']) ?>
                                            </span>
                                    </td>
                                </tr>
                            </table>
                        </div>
                    </div>
                </div>

                <!-- Informasi Pembayaran -->
                <div class="col-md-6 mb-4">
                    <div class="card">
                        <div class="card-header">
                            <h5 class="card-title mb-0">Informasi Pembayaran</h5>
                        </div>
                        <div class="card-body">
                            <table class="table table-borderless">
                                <tr>
                                    <th width="40%">Total Bayar</th>
                                    <td>Rp <?= number_format($detail['total_bayar'], 0, ',', '.') ?></td>
                                </tr>
                                <tr>
                                    <th>Metode Pembayaran</th>
                                    <td><?= htmlspecialchars($detail['nama_metode'] ?? '-') ?></td>
                                </tr>
                                <tr>
                                    <th>Tanggal Pembayaran</th>
                                    <td><?= htmlspecialchars($detail['tanggal_pembayaran'] ?? '-') ?></td>
                                </tr>
                            </table>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Bootstrap Bundle JS -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
