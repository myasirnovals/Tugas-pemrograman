<?php
session_start();

require_once '../../../config/config.php';

if (!isset($_GET['id'])) {
    header('Location: pelanggan.php?status=error&message=ID Pelanggan tidak ditemukan');
    exit;
}

$id_pelanggan = $_GET['id'];

$query_pelanggan = "SELECT p.*, a.* 
                    FROM pelanggan p 
                    JOIN alamat a ON p.kode_alamat = a.kode_alamat 
                    WHERE p.id_pelanggan = :id";
$stmt = $conn->prepare($query_pelanggan);
$stmt->execute(['id' => $id_pelanggan]);
$pelanggan = $stmt->fetch(PDO::FETCH_ASSOC);

if (!$pelanggan) {
    header('Location: pelanggan.php?status=error&message=Data pelanggan tidak ditemukan');
    exit;
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        $conn->beginTransaction();

        $query_alamat = "UPDATE alamat SET 
                        jalan = :jalan,
                        desa = :desa,
                        kota = :kota,
                        provinsi = :provinsi,
                        negara = :negara,
                        kode_pos = :kode_pos
                        WHERE kode_alamat = :kode_alamat";

        $stmt_alamat = $conn->prepare($query_alamat);
        $stmt_alamat->execute([
            'jalan' => $_POST['jalan'],
            'desa' => $_POST['desa'],
            'kota' => $_POST['kota'],
            'provinsi' => $_POST['provinsi'],
            'negara' => $_POST['negara'],
            'kode_pos' => $_POST['kode_pos'],
            'kode_alamat' => $pelanggan['kode_alamat']
        ]);

        $query_update = "UPDATE pelanggan SET 
                        nama_pelanggan = :nama,
                        email = :email,
                        no_hp = :no_hp
                        WHERE id_pelanggan = :id";

        $stmt_update = $conn->prepare($query_update);
        $stmt_update->execute([
            'nama' => $_POST['nama_pelanggan'],
            'email' => $_POST['email'],
            'no_hp' => $_POST['no_hp'],
            'id' => $id_pelanggan
        ]);

        $conn->commit();
        header('Location: pelanggan.php?status=success&message=Data pelanggan berhasil diperbarui');
        exit;

    } catch (PDOException $e) {
        $conn->rollBack();
        header('Location: pelanggan.php?status=error&message=Gagal memperbarui data: ' . $e->getMessage());
        exit;
    }
}
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Update Pelanggan - Hotel Reservation</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.css" rel="stylesheet">
    <link rel="stylesheet" href="pelanggan.css">
</head>
<body>
<div class="container-fluid">
    <div class="row">
        <!-- Sidebar -->
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
                <h1 class="h2">Update Data Pelanggan</h1>
                <a href="pelanggan.php" class="btn btn-secondary">
                    <i class="bi bi-arrow-left"></i> Kembali
                </a>
            </div>

            <div class="card">
                <div class="card-body">
                    <form action="" method="POST" class="needs-validation" novalidate>
                        <!-- Data Pelanggan -->
                        <h5 class="mb-3">Data Pelanggan</h5>
                        <div class="row mb-4">
                            <div class="col-md-6">
                                <div class="mb-3">
                                    <label for="nama_pelanggan" class="form-label">Nama Pelanggan</label>
                                    <input type="text" class="form-control" id="nama_pelanggan" name="nama_pelanggan"
                                           value="<?= htmlspecialchars($pelanggan['nama_pelanggan']) ?>" required>
                                    <div class="invalid-feedback">
                                        Nama pelanggan harus diisi
                                    </div>
                                </div>
                                <div class="mb-3">
                                    <label for="email" class="form-label">Email</label>
                                    <input type="email" class="form-control" id="email" name="email"
                                           value="<?= htmlspecialchars($pelanggan['email']) ?>" required>
                                    <div class="invalid-feedback">
                                        Email harus diisi dengan format yang benar
                                    </div>
                                </div>
                                <div class="mb-3">
                                    <label for="no_hp" class="form-label">No. Telepon</label>
                                    <input type="tel" class="form-control" id="no_hp" name="no_hp"
                                           value="<?= htmlspecialchars($pelanggan['no_hp']) ?>" required>
                                    <div class="invalid-feedback">
                                        No. Telepon harus diisi
                                    </div>
                                </div>
                            </div>
                        </div>

                        <!-- Data Alamat -->
                        <h5 class="mb-3">Data Alamat</h5>
                        <div class="row">
                            <div class="col-md-6">
                                <div class="mb-3">
                                    <label for="jalan" class="form-label">Jalan</label>
                                    <input type="text" class="form-control" id="jalan" name="jalan"
                                           value="<?= htmlspecialchars($pelanggan['jalan']) ?>" required>
                                </div>
                                <div class="mb-3">
                                    <label for="desa" class="form-label">Desa/Kelurahan</label>
                                    <input type="text" class="form-control" id="desa" name="desa"
                                           value="<?= htmlspecialchars($pelanggan['desa']) ?>" required>
                                </div>
                                <div class="mb-3">
                                    <label for="kota" class="form-label">Kota</label>
                                    <input type="text" class="form-control" id="kota" name="kota"
                                           value="<?= htmlspecialchars($pelanggan['kota']) ?>" required>
                                </div>
                            </div>
                            <div class="col-md-6">
                                <div class="mb-3">
                                    <label for="provinsi" class="form-label">Provinsi</label>
                                    <input type="text" class="form-control" id="provinsi" name="provinsi"
                                           value="<?= htmlspecialchars($pelanggan['provinsi']) ?>" required>
                                </div>
                                <div class="mb-3">
                                    <label for="negara" class="form-label">Negara</label>
                                    <input type="text" class="form-control" id="negara" name="negara"
                                           value="<?= htmlspecialchars($pelanggan['negara']) ?>" required>
                                </div>
                                <div class="mb-3">
                                    <label for="kode_pos" class="form-label">Kode Pos</label>
                                    <input type="text" class="form-control" id="kode_pos" name="kode_pos"
                                           value="<?= htmlspecialchars($pelanggan['kode_pos']) ?>" required>
                                </div>
                            </div>
                        </div>

                        <div class="mt-4">
                            <button type="submit" class="btn btn-primary">
                                <i class="bi bi-save"></i> Simpan Perubahan
                            </button>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
<script>
    (function () {
        'use strict'
        var forms = document.querySelectorAll('.needs-validation')
        Array.prototype.slice.call(forms)
            .forEach(function (form) {
                form.addEventListener('submit', function (event) {
                    if (!form.checkValidity()) {
                        event.preventDefault()
                        event.stopPropagation()
                    }
                    form.classList.add('was-validated')
                }, false)
            })
    })()
</script>
</body>
</html>
