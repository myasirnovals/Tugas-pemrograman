<!DOCTYPE html>
<html lang="id">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Pembayaran - Hotel Reservation</title>
    <!-- Bootstrap 5.3.2 CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" />
    <!-- Bootstrap Icons -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet" />
    <link rel="stylesheet" href="pembayaran.css" />
    <style></style>
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
            <button class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#addPembayaranModal"><i class="bi bi-plus-circle me-2"></i>Tambah Pembayaran</button>
          </div>

          <!-- Summary Cards -->
          <div class="row mb-4">
            <div class="col-md-3">
              <div class="card payment-card bg-primary text-white">
                <div class="card-body">
                  <h6 class="card-title">Total Pembayaran Hari Ini</h6>
                  <h3 class="mb-0">Rp 7</h3>
                </div>
              </div>
            </div>
            <div class="col-md-3">
              <div class="card payment-card bg-success text-white">
                <div class="card-body">
                  <h6 class="card-title">Pembayaran Lunas</h6>
                  <h3 class="mb-0">7</h3>
                </div>
              </div>
            </div>
            <div class="col-md-3">
              <div class="card payment-card bg-warning text-white">
                <div class="card-body">
                  <h6 class="card-title">Menunggu Pembayaran</h6>
                  <h3 class="mb-0">7</h3>
                </div>
              </div>
            </div>
            <div class="col-md-3">
              <div class="card payment-card bg-danger text-white">
                <div class="card-body">
                  <h6 class="card-title">Pembayaran Gagal</h6>
                  <h3 class="mb-0">7</h3>
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
                    <tr>
                      <td>00000</td>
                      <td>00000</td>
                      <td>2024-12-26</td>
                      <td>Transfer Bank</td>
                      <td>Rp 1.600.000</td>
                      <td><span class="badge bg-success">Lunas</span></td>
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
                    <tr>
                      <td>00000</td>
                      <td>00000</td>
                      <td>2024-01-16</td>
                      <td>Kartu Kredit</td>
                      <td>Rp 2.400.000</td>
                      <td><span class="badge bg-warning">Pending</span></td>
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
                  </tbody>
                </table>
              </div>

              <!-- Pagination -->
              <nav aria-label="Page navigation" class="mt-4">
                <ul class="pagination justify-content-center">
                  <li class="page-item disabled">
                    <a class="page-link" href="#" tabindex="-1">Previous</a>
                  </li>
                  <li class="page-item active"><a class="page-link" href="#">1</a></li>
                  <li class="page-item"><a class="page-link" href="#">2</a></li>
                  <li class="page-item"><a class="page-link" href="#">3</a></li>
                  <li class="page-item">
                    <a class="page-link" href="#">Next</a>
                  </li>
                </ul>
              </nav>
            </div>
          </div>
        </div>
      </div>
    </div>

    <!-- Bootstrap Bundle JS -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
  </body>
</html>
