<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title>Dashboard Admin - Hotel Reservation</title>
    <!-- Bootstrap 5.3.2 CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet"/>
    <!-- Bootstrap Icons -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet"/>
    <link rel="stylesheet" href="dashboard.css"/>
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
                        <a href="dashboard.php" class="nav-link active">
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
            <!-- Dashboard Overview -->
            <div class="row mb-4">
                <div class="col-12">
                    <h1 class="h2 mb-4">Dashboard</h1>
                </div>
                <!-- Stat Cards -->
                <div class="col-md-3 mb-4">
                    <div class="card bg-primary text-white">
                        <div class="card-body">
                            <h5 class="card-title">Total Pelanggan</h5>
                            <h2 class="mb-0">7</h2>
                        </div>
                    </div>
                </div>
                <div class="col-md-3 mb-4">
                    <div class="card bg-success text-white">
                        <div class="card-body">
                            <h5 class="card-title">Reservasi Aktif</h5>
                            <h2 class="mb-0">7</h2>
                        </div>
                    </div>
                </div>
                <div class="col-md-3 mb-4">
                    <div class="card bg-info text-white">
                        <div class="card-body">
                            <h5 class="card-title">Kamar Tersedia</h5>
                            <h2 class="mb-0">7</h2>
                        </div>
                    </div>
                </div>
                <div class="col-md-3 mb-4">
                    <div class="card bg-warning text-white">
                        <div class="card-body">
                            <h5 class="card-title">Pending Payment</h5>
                            <h2 class="mb-0">7</h2>
                        </div>
                    </div>
                </div>
            </div>

            <!-- Recent Reservations -->
            <div class="card mb-4">
                <div class="card-header">
                    <h5 class="card-title mb-0">Reservasi Terbaru</h5>
                </div>
                <div class="card-body">
                    <div class="table-responsive">
                        <table class="table table-hover">
                            <thead>
                            <tr>
                                <th>ID Reservasi</th>
                                <th>Nama Pelanggan</th>
                                <th>Check-in</th>
                                <th>Check-out</th>
                                <th>Status</th>
                                <th>Aksi</th>
                            </tr>
                            </thead>
                            <tbody>
                            <tr>
                                <td>00000</td>
                                <td>Arya</td>
                                <td>2024-12-26</td>
                                <td>2024-12-26</td>
                                <td><span class="badge bg-success">Confirmed</span></td>
                                <td>
                                    <button class="btn btn-sm btn-primary"><i class="bi bi-eye"></i></button>
                                    <button class="btn btn-sm btn-warning"><i class="bi bi-pencil"></i></button>
                                    <button class="btn btn-sm btn-danger"><i class="bi bi-trash"></i></button>
                                </td>
                            </tr>
                            <tr>
                                <td>00000</td>
                                <td>Yasir</td>
                                <td>2024-12-26</td>
                                <td>2024-12-26</td>
                                <td><span class="badge bg-warning">Pending</span></td>
                                <td>
                                    <button class="btn btn-sm btn-primary"><i class="bi bi-eye"></i></button>
                                    <button class="btn btn-sm btn-warning"><i class="bi bi-pencil"></i></button>
                                    <button class="btn btn-sm btn-danger"><i class="bi bi-trash"></i></button>
                                </td>
                            </tr>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Bootstrap Bundle JS -->
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js" rel="stylesheet"/>
</body>
</html>
