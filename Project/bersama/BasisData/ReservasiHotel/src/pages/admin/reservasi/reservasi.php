<?php
require_once '../../../config/config.php';

// Query untuk membaca data reservasi dengan JOIN ke tabel pelanggan
$query = "SELECT r.*, p.nama_pelanggan 
          FROM reservasi as r 
          JOIN pelanggan as p ON r.id_pelanggan = p.id_pelanggan 
          ORDER BY r.tanggal_reservasi ASC";
$stmt = $conn->prepare($query);
$stmt->execute();
$reservasi = $stmt->fetchAll(PDO::FETCH_ASSOC);

// Fungsi untuk mengubah format status menjadi badge
function getStatusBadge($status)
{
    switch (strtolower($status)) {
        case 'confirmed':
            return '<span class="badge bg-success">Confirmed</span>';
        case 'pending':
            return '<span class="badge bg-warning">Pending</span>';
        case 'cancelled':
            return '<span class="badge bg-danger">Cancelled</span>';
        default:
            return '<span class="badge bg-secondary">' . $status . '</span>';
    }
}

?>
<!DOCTYPE html>
<html lang="id">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Reservasi - Hotel Reservation</title>
    <!-- Bootstrap 5.3.2 CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" />
    <!-- Bootstrap Icons -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet" />
    <link rel="stylesheet" href="reservasi.css" />
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
          </div>
        </div>

        <!-- Main Content -->
        <div class="col-md-9 col-lg-10 content">
            <div class="d-flex justify-content-between align-items-center mb-4">
                <h1 class="h2">Data Reservasi</h1>
            </div>

            <?php if (isset($_GET['status'])) { ?>
                <div class="alert alert-<?= $_GET['status'] == 'success' ? 'success' : 'danger' ?> alert-dismissible fade show"
                     role="alert">
                    <?= $_GET['message'] ?>
                    <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
                </div>
            <?php } ?>

            <!-- Reservasi Table -->
            <div class="card">
                <div class="card-body">
                    <div class="table-responsive">
                        <table class="table table-hover">
                            <thead>
                            <tr>
                                <th>ID Reservasi</th>
                                <th>Nama Pelanggan</th>
                                <th>Tanggal Reservasi</th>
                                <th>Check In</th>
                                <th>Check Out</th>
                                <th>Status</th>
                                <th>Aksi</th>
                            </tr>
                            </thead>
                            <tbody>
                            <?php foreach ($reservasi as $r) { ?>
                                <tr>
                                    <td><?= htmlspecialchars($r['id_reservasi']) ?></td>
                                    <td><?= htmlspecialchars($r['nama_pelanggan']) ?></td>
                                    <td><?= htmlspecialchars($r['tanggal_reservasi']) ?></td>
                                    <td><?= htmlspecialchars($r['tanggal_checkin']) ?></td>
                                    <td><?= htmlspecialchars($r['tanggal_checkout']) ?></td>
                                    <td><?= getStatusBadge($r['status']) ?></td>
                                    <td>
                                        <a href="detail.php?id=<?= $r['id_reservasi'] ?>"
                                           class="btn btn-sm btn-primary">
                                            <i class="bi bi-eye"></i>
                                        </a>
                                        <a href="update.php?id=<?= $r['id_reservasi'] ?>"
                                           class="btn btn-sm btn-warning">
                                            <i class="bi bi-pencil"></i>
                                        </a>
                                        <button type="button"
                                                onclick="confirmDelete('<?= $r['id_reservasi'] ?>')"
                                                class="btn btn-sm btn-danger">
                                            <i class="bi bi-trash"></i>
                                        </button>
                                    </td>
                                </tr>
                            <?php } ?>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Modal Konfirmasi Delete -->
<div class="modal fade" id="deleteModal" tabindex="-1">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title">Konfirmasi Hapus</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
            </div>
            <div class="modal-body">
                <p>Apakah Anda yakin ingin menghapus reservasi ini?</p>
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Batal</button>
                <form id="deleteForm" action="delete.php" method="POST" class="d-inline">
                    <input type="hidden" name="id_reservasi" id="deleteId">
                    <button type="submit" class="btn btn-danger">Hapus</button>
                </form>
            </div>
        </div>
    </div>
</div>

<!-- Script untuk modal delete -->
<script>
    function confirmDelete(id) {
        document.getElementById('deleteId').value = id;
        var deleteModal = new bootstrap.Modal(document.getElementById('deleteModal'));
        deleteModal.show();
    }
</script>

<!-- Bootstrap Bundle JS -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>