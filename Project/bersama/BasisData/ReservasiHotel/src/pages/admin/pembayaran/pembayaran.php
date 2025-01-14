<?php
require_once '../../../config/config.php';

$tahunIni = date('Y');

$queryTotal = "SELECT COUNT(*) as total FROM pembayaran 
               WHERE YEAR(tanggal_pembayaran) = :tahun";
$stmtTotal = $conn->prepare($queryTotal);
$stmtTotal->execute([':tahun' => $tahunIni]);
$totalPembayaran = $stmtTotal->fetch(PDO::FETCH_ASSOC)['total'];

$queryLunas = "SELECT COUNT(*) as total FROM pembayaran p
               JOIN reservasi r ON p.id_reservasi = r.id_reservasi
               WHERE r.status = 'Confirmed' AND YEAR(p.tanggal_pembayaran) = :tahun";
$stmtLunas = $conn->prepare($queryLunas);
$stmtLunas->execute([':tahun' => $tahunIni]);
$pembayaranLunas = $stmtLunas->fetch(PDO::FETCH_ASSOC)['total'];

$queryPending = "SELECT COUNT(*) as total FROM pembayaran p
                JOIN reservasi r ON p.id_reservasi = r.id_reservasi
                WHERE r.status = 'Pending' AND YEAR(p.tanggal_pembayaran) = :tahun";
$stmtPending = $conn->prepare($queryPending);
$stmtPending->execute([':tahun' => $tahunIni]);
$pembayaranPending = $stmtPending->fetch(PDO::FETCH_ASSOC)['total'];

$queryGagal = "SELECT COUNT(*) as total FROM pembayaran p
               JOIN reservasi r ON p.id_reservasi = r.id_reservasi
               WHERE r.status = 'Cancelled' AND YEAR(p.tanggal_pembayaran) = :tahun";
$stmtGagal = $conn->prepare($queryGagal);
$stmtGagal->execute([':tahun' => $tahunIni]);
$pembayaranGagal = $stmtGagal->fetch(PDO::FETCH_ASSOC)['total'];

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
          ORDER BY p.tanggal_pembayaran ASC";

$stmt = $conn->prepare($query);
$stmt->execute();
$pembayarans = $stmt->fetchAll(PDO::FETCH_ASSOC);

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
    <meta charset="UTF-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title>Pembayaran - Hotel Reservation</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet"/>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet"/>
    <link rel="stylesheet" href="pembayaran.css"/>
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
                    <div class="card bg-primary text-white">
                        <div class="card-body">
                            <h6 class="card-title">Total Pembayaran Tahun <?= $tahunIni ?></h6>
                            <h2 class="card-text"><?= $totalPembayaran ?></h2>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="card bg-success text-white">
                        <div class="card-body">
                            <h6 class="card-title">Pembayaran Lunas</h6>
                            <h2 class="card-text"><?= $pembayaranLunas ?></h2>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="card bg-warning text-white">
                        <div class="card-body">
                            <h6 class="card-title">Menunggu Pembayaran</h6>
                            <h2 class="card-text"><?= $pembayaranPending ?></h2>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="card bg-danger text-white">
                        <div class="card-body">
                            <h6 class="card-title">Pembayaran Gagal</h6>
                            <h2 class="card-text"><?= $pembayaranGagal ?></h2>
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
                                    <td class="text-center">
                                        <div class="btn-group" role="group">
                                            <button class="btn btn-sm btn-warning" title="Edit"
                                                    onclick="editPembayaran('<?= $pembayaran['id_pembayaran'] ?>')">
                                                <i class="bi bi-pencil"></i>
                                            </button>
                                            <button class="btn btn-sm btn-danger" title="Hapus"
                                                    onclick="deletePembayaran('<?= $pembayaran['id_pembayaran'] ?>')">
                                                <i class="bi bi-trash"></i>
                                            </button>
                                        </div>
                                    </td>
                                </tr>
                            <?php endforeach; ?>
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
        <!-- Alert Messages -->
        <?php if (isset($_GET['status']) && isset($_GET['message'])): ?>
            <div class="alert alert-<?= $_GET['status'] === 'success' ? 'success' : 'danger' ?> alert-dismissible fade show"
                 role="alert">
                <?= htmlspecialchars($_GET['message']) ?>
                <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
            </div>
        <?php endif; ?>
    </div>
</div>

<!-- Modal Tambah Pembayaran -->
<div class="modal fade" id="addPembayaranModal" tabindex="-1" aria-labelledby="addPembayaranModalLabel"
     aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="addPembayaranModalLabel">Tambah Pembayaran Baru</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <form action="create.php" method="POST">
                <div class="modal-body">
                    <div class="mb-3">
                        <label for="id_reservasi" class="form-label">ID Reservasi</label>
                        <select class="form-select" id="id_reservasi" name="id_reservasi" required>
                            <option value="">Pilih Reservasi</option>
                            <?php
                            $queryReservasi = "SELECT r.id_reservasi, p.nama_pelanggan 
                                             FROM reservasi r 
                                             JOIN pelanggan p ON r.id_pelanggan = p.id_pelanggan 
                                             WHERE r.status = 'Pending'";
                            $stmtReservasi = $conn->prepare($queryReservasi);
                            $stmtReservasi->execute();
                            while ($row = $stmtReservasi->fetch(PDO::FETCH_ASSOC)) {
                                echo "<option value='" . $row['id_reservasi'] . "'>" .
                                    $row['id_reservasi'] . " - " . $row['nama_pelanggan'] . "</option>";
                            }
                            ?>
                        </select>
                    </div>
                    <div class="mb-3">
                        <label for="metode_pembayaran" class="form-label">Metode Pembayaran</label>
                        <select class="form-select" id="metode_pembayaran" name="kode_mp" required>
                            <option value="">Pilih Metode Pembayaran</option>
                            <?php
                            $queryMetode = "SELECT * FROM metode_pembayaran";
                            $stmtMetode = $conn->prepare($queryMetode);
                            $stmtMetode->execute();
                            while ($row = $stmtMetode->fetch(PDO::FETCH_ASSOC)) {
                                echo "<option value='" . $row['kode_mp'] . "'>" . $row['nama_metode'] . "</option>";
                            }
                            ?>
                        </select>
                    </div>
                    <div class="mb-3">
                        <label for="total_bayar" class="form-label">Total Bayar</label>
                        <input type="number" class="form-control" id="total_bayar" name="total_bayar" required>
                    </div>
                    <div class="mb-3">
                        <label for="tanggal_pembayaran" class="form-label">Tanggal Pembayaran</label>
                        <input type="date" class="form-control" id="tanggal_pembayaran" name="tanggal_pembayaran"
                               value="<?= date('Y-m-d') ?>" required>
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

<!-- Modal Edit Pembayaran -->
<div class="modal fade" id="editPembayaranModal" tabindex="-1" aria-labelledby="editPembayaranModalLabel"
     aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="editPembayaranModalLabel">Edit Pembayaran</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <form action="update.php" method="POST">
                <div class="modal-body">
                    <input type="hidden" id="edit_id_pembayaran" name="id_pembayaran">
                    <div class="mb-3">
                        <label for="edit_id_reservasi" class="form-label">ID Reservasi</label>
                        <input type="text" class="form-control" id="edit_id_reservasi" readonly>
                    </div>
                    <div class="mb-3">
                        <label for="edit_metode_pembayaran" class="form-label">Metode Pembayaran</label>
                        <select class="form-select" id="edit_metode_pembayaran" name="kode_mp" required>
                            <?php
                            $queryMetode = "SELECT * FROM metode_pembayaran";
                            $stmtMetode = $conn->prepare($queryMetode);
                            $stmtMetode->execute();
                            while ($row = $stmtMetode->fetch(PDO::FETCH_ASSOC)) {
                                echo "<option value='" . $row['kode_mp'] . "'>" . $row['nama_metode'] . "</option>";
                            }
                            ?>
                        </select>
                    </div>
                    <div class="mb-3">
                        <label for="edit_total_bayar" class="form-label">Total Bayar</label>
                        <input type="number" class="form-control" id="edit_total_bayar" name="total_bayar" required>
                    </div>
                    <div class="mb-3">
                        <label for="edit_tanggal_pembayaran" class="form-label">Tanggal Pembayaran</label>
                        <input type="date" class="form-control" id="edit_tanggal_pembayaran" name="tanggal_pembayaran"
                               required>
                    </div>
                    <div class="mb-3">
                        <label for="edit_status" class="form-label">Status Pembayaran</label>
                        <select class="form-select" id="edit_status" name="status" required>
                            <option value="Pending">Pending</option>
                            <option value="Confirmed">Lunas</option>
                            <option value="Cancelled">Gagal</option>
                        </select>
                    </div>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Batal</button>
                    <button type="submit" class="btn btn-primary">Simpan Perubahan</button>
                </div>
            </form>
        </div>
    </div>
</div>

<!-- Modal Konfirmasi Hapus -->
<div class="modal fade" id="deletePembayaranModal" tabindex="-1" aria-labelledby="deletePembayaranModalLabel"
     aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="deletePembayaranModalLabel">Konfirmasi Hapus</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <div class="modal-body">
                <p>Anda yakin ingin menghapus data pembayaran ini?</p>
                <p class="text-danger"><small>Tindakan ini tidak dapat dibatalkan dan akan mengubah status reservasi
                        menjadi Pending.</small></p>
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Batal</button>
                <form action="delete.php" method="POST" class="d-inline">
                    <input type="hidden" id="delete_id_pembayaran" name="id_pembayaran">
                    <button type="submit" class="btn btn-danger">Hapus</button>
                </form>
            </div>
        </div>
    </div>
</div>


<script>
    function deletePembayaran(id) {
        document.getElementById('delete_id_pembayaran').value = id;
        new bootstrap.Modal(document.getElementById('deletePembayaranModal')).show();
    }

    function editPembayaran(id) {
        // Ambil data pembayaran dengan AJAX
        fetch(`get_pembayaran.php?id=${id}`)
            .then(response => response.json())
            .then(data => {
                // Isi form dengan data yang ada
                document.getElementById('edit_id_pembayaran').value = data.id_pembayaran;
                document.getElementById('edit_id_reservasi').value = data.id_reservasi;
                document.getElementById('edit_metode_pembayaran').value = data.kode_mp;
                document.getElementById('edit_total_bayar').value = data.total_bayar;
                document.getElementById('edit_tanggal_pembayaran').value = data.tanggal_pembayaran;
                document.getElementById('edit_status').value = data.status;

                // Tampilkan modal
                new bootstrap.Modal(document.getElementById('editPembayaranModal')).show();
            })
            .catch(error => {
                alert('Terjadi kesalahan saat mengambil data pembayaran');
                console.error('Error:', error);
            });
    }
</script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
