<?php
session_start();

require_once '../../../config/config.php';

$query = "SELECT k.*, tk.nama_tipe, tk.biaya 
          FROM kamar k
          LEFT JOIN tipe_kamar tk ON k.id_tipe = tk.id_tipe
          ORDER BY k.nomor_kamar ASC";
$stmt = $conn->prepare($query);
$stmt->execute();
$kamar = $stmt->fetchAll(PDO::FETCH_ASSOC);

function getStatusBadge($status)
{
    switch (strtolower($status)) {
        case 'available':
            return '<span class="badge bg-success">Available</span>';
        case 'occupied':
            return '<span class="badge bg-danger">Occupied</span>';
        case 'reserved':
            return '<span class="badge bg-warning">Reserved</span>';
        default:
            return '<span class="badge bg-secondary">' . $status . '</span>';
    }
}

function formatRupiah($angka)
{
    return 'Rp ' . number_format($angka, 0, ',', '.');
}

?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title>Kamar - Hotel Reservation</title>
    <!-- Bootstrap 5.3.2 CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet"/>
    <!-- Bootstrap Icons -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet"/>
    <link rel="stylesheet" href="kamar.css"/>
</head>
<body>
<div class="container-fluid">
    <div class="row">
        <!-- Sidebar (same as before) -->
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
                <h1 class="h2">Data Kamar</h1>
                <button class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#addKamarModal">
                    <i class="bi bi-plus-circle me-2"></i>Tambah Kamar
                </button>
            </div>

            <?php if (isset($_GET['status'])) { ?>
                <div class="alert alert-<?= $_GET['status'] == 'success' ? 'success' : 'danger' ?> alert-dismissible fade show"
                     role="alert">
                    <?= htmlspecialchars($_GET['message']) ?>
                    <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
                </div>
            <?php } ?>

            <!-- Kamar Table -->
            <div class="card">
                <div class="card-body">
                    <div class="table-responsive">
                        <table class="table table-hover">
                            <thead>
                            <tr>
                                <th>ID Kamar</th>
                                <th>Nomor Kamar</th>
                                <th>Tipe Kamar</th>
                                <th>Biaya per Hari</th>
                                <th>Status</th>
                                <th>Aksi</th>
                            </tr>
                            </thead>
                            <tbody>
                            <?php foreach ($kamar as $k) { ?>
                                <tr>
                                    <td><?= htmlspecialchars($k['id_kamar']) ?></td>
                                    <td><?= htmlspecialchars($k['nomor_kamar']) ?></td>
                                    <td><?= htmlspecialchars($k['nama_tipe']) ?></td>
                                    <td><?= formatRupiah($k['biaya']) ?></td>
                                    <td><?= getStatusBadge($k['status']) ?></td>
                                    <td>
                                        <button class="btn btn-sm btn-primary"
                                                onclick="viewKamar(<?= $k['id_kamar'] ?>)">
                                            <i class="bi bi-eye"></i>
                                        </button>
                                        <button class="btn btn-sm btn-warning"
                                                onclick="editKamar(<?= $k['id_kamar'] ?>)">
                                            <i class="bi bi-pencil"></i>
                                        </button>
                                        <button type="button"
                                                class="btn btn-sm btn-danger"
                                                data-bs-toggle="modal"
                                                data-bs-target="#deleteModal"
                                                onclick="setDeleteId(<?= $k['id_kamar'] ?>, '<?= htmlspecialchars($k['nomor_kamar']) ?>')">
                                            <i class="bi bi-trash"></i>
                                        </button>
                                    </td>
                                </tr>
                            <?php } ?>
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

<!-- Modal Tambah Kamar -->
<div class="modal fade" id="addKamarModal" tabindex="-1">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title">Tambah Kamar Baru</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
            </div>
            <form action="create.php" method="POST">
                <div class="modal-body">
                    <div class="mb-3">
                        <label for="nomor_kamar" class="form-label">Nomor Kamar</label>
                        <input type="text" class="form-control" id="nomor_kamar" name="nomor_kamar"
                               required maxlength="3" pattern="[0-9]{3}"
                               placeholder="Contoh: 101">
                        <div class="form-text">Masukkan 3 digit nomor kamar</div>
                    </div>

                    <div class="mb-3">
                        <label for="id_tipe" class="form-label">Tipe Kamar</label>
                        <select class="form-select" id="id_tipe" name="id_tipe" required>
                            <option value="">Pilih Tipe Kamar</option>
                            <?php
                            $query_tipe = "SELECT * FROM tipe_kamar ORDER BY nama_tipe";
                            $stmt_tipe = $conn->prepare($query_tipe);
                            $stmt_tipe->execute();
                            while ($tipe = $stmt_tipe->fetch(PDO::FETCH_ASSOC)) {
                                echo "<option value='" . $tipe['id_tipe'] . "'>" .
                                    htmlspecialchars($tipe['nama_tipe']) . " - " .
                                    formatRupiah($tipe['biaya']) . "</option>";
                            }
                            ?>
                        </select>
                    </div>

                    <div class="mb-3">
                        <label for="status" class="form-label">Status</label>
                        <select class="form-select" id="status" name="status" required>
                            <option value="">Pilih Status</option>
                            <option value="Available">Available</option>
                            <option value="Occupied">Occupied</option>
                            <option value="Reserved">Reserved</option>
                        </select>
                    </div>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Batal</button>
                    <button type="submit" class="btn btn-primary">Simpan</button>
                </div>
            </form>
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
                <p>Anda yakin ingin menghapus kamar nomor <strong id="deleteRoomNumber"></strong>?</p>
                <p class="text-danger"><small>Tindakan ini tidak dapat dibatalkan.</small></p>
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Batal</button>
                <form id="deleteForm" action="delete.php" method="POST">
                    <input type="hidden" name="id_kamar" id="deleteId">
                    <button type="submit" class="btn btn-danger">Hapus</button>
                </form>
            </div>
        </div>
    </div>
</div>

<script>
    function viewKamar(id) {
        window.location.href = `detail.php?id=${id}`;
    }

    function editKamar(id) {
        window.location.href = `edit.php?id=${id}`;
    }

    function setDeleteId(id, roomNumber) {
        document.getElementById('deleteId').value = id;
        document.getElementById('deleteRoomNumber').textContent = roomNumber;
    }

    document.addEventListener('DOMContentLoaded', function () {
        const alerts = document.querySelectorAll('.alert');
        alerts.forEach(function (alert) {
            setTimeout(function () {
                const bsAlert = new bootstrap.Alert(alert);
                bsAlert.close();
            }, 5000);
        });
    });
</script>

<!-- Bootstrap Bundle JS -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
