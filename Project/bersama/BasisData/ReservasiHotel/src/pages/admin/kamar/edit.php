<?php
require_once '../../../config/config.php';

// Cek apakah ada ID kamar
if (!isset($_GET['id']) || empty($_GET['id'])) {
    header('Location: kamar.php?status=error&message=ID Kamar tidak valid');
    exit;
}

try {
    $id_kamar = $_GET['id'];

    $query = "SELECT k.*, tk.nama_tipe, tk.biaya 
              FROM kamar k
              JOIN tipe_kamar tk ON k.id_tipe = tk.id_tipe
              WHERE k.id_kamar = :id_kamar";

    $stmt = $conn->prepare($query);
    $stmt->execute(['id_kamar' => $id_kamar]);
    $kamar = $stmt->fetch(PDO::FETCH_ASSOC);

    if (!$kamar) {
        throw new Exception('Data kamar tidak ditemukan');
    }

    $query_tipe = "SELECT * FROM tipe_kamar ORDER BY nama_tipe";
    $stmt_tipe = $conn->prepare($query_tipe);
    $stmt_tipe->execute();
    $tipe_kamar = $stmt_tipe->fetchAll(PDO::FETCH_ASSOC);

} catch (Exception $e) {
    header('Location: kamar.php?status=error&message=' . urlencode($e->getMessage()));
    exit;
}

function formatRupiah($angka) {
    return 'Rp ' . number_format($angka, 0, ',', '.');
}
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit Kamar - Hotel Reservation</title>
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
                <h1 class="h2">Edit Kamar</h1>
                <a href="kamar.php" class="btn btn-secondary">
                    <i class="bi bi-arrow-left me-2"></i>Kembali
                </a>
            </div>

            <div class="card">
                <div class="card-body">
                    <form action="update.php" method="POST" id="editForm">
                        <input type="hidden" name="id_kamar" value="<?= htmlspecialchars($kamar['id_kamar']) ?>">

                        <div class="mb-3">
                            <label for="nomor_kamar" class="form-label">Nomor Kamar</label>
                            <input type="text" class="form-control" id="nomor_kamar" name="nomor_kamar"
                                   required maxlength="3" pattern="[0-9]{3}"
                                   value="<?= htmlspecialchars($kamar['nomor_kamar']) ?>"
                                   placeholder="Contoh: 101">
                            <div class="form-text">Masukkan 3 digit nomor kamar</div>
                        </div>

                        <div class="mb-3">
                            <label for="id_tipe" class="form-label">Tipe Kamar</label>
                            <select class="form-select" id="id_tipe" name="id_tipe" required>
                                <option value="">Pilih Tipe Kamar</option>
                                <?php foreach ($tipe_kamar as $tipe): ?>
                                    <option value="<?= $tipe['id_tipe'] ?>"
                                        <?= ($tipe['id_tipe'] == $kamar['id_tipe']) ? 'selected' : '' ?>>
                                        <?= htmlspecialchars($tipe['nama_tipe']) ?> -
                                        <?= formatRupiah($tipe['biaya']) ?>
                                    </option>
                                <?php endforeach; ?>
                            </select>
                        </div>

                        <div class="mb-3">
                            <label for="status" class="form-label">Status</label>
                            <select class="form-select" id="status" name="status" required>
                                <option value="">Pilih Status</option>
                                <?php
                                $status_list = ['Available', 'Occupied', 'Reserved'];
                                foreach ($status_list as $status):
                                    ?>
                                    <option value="<?= $status ?>"
                                        <?= ($status == $kamar['status']) ? 'selected' : '' ?>>
                                        <?= $status ?>
                                    </option>
                                <?php endforeach; ?>
                            </select>
                        </div>

                        <div class="d-flex justify-content-end gap-2">
                            <a href="kamar.php" class="btn btn-secondary">Batal</a>
                            <button type="submit" class="btn btn-primary">Simpan Perubahan</button>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Bootstrap JS -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>

<script>
    document.getElementById('editForm').onsubmit = function(e) {
        const nomorKamar = document.getElementById('nomor_kamar').value;
        const idTipe = document.getElementById('id_tipe').value;
        const status = document.getElementById('status').value;

        if (!nomorKamar.match(/^[0-9]{3}$/)) {
            alert('Nomor kamar harus terdiri dari 3 digit angka');
            e.preventDefault();
            return false;
        }

        if (!idTipe) {
            alert('Silakan pilih tipe kamar');
            e.preventDefault();
            return false;
        }

        if (!status) {
            alert('Silakan pilih status kamar');
            e.preventDefault();
            return false;
        }

        return true;
    };
</script>
</body>
</html>
