Copy
<?php
session_start();
require_once "config/config.php";

// Ambil data tipe kamar dari database
$queryTipeKamar = "SELECT id_tipe, nama_tipe, biaya FROM tipe_kamar";
$stmtTipeKamar = $conn->query($queryTipeKamar);
$tipeKamar = $stmtTipeKamar->fetchAll(PDO::FETCH_ASSOC);

// Ambil data metode pembayaran dari database
$queryMP = "SELECT kode_mp, nama_metode FROM metode_pembayaran";
$stmtMP = $conn->query($queryMP);
$metodePembayaran = $stmtMP->fetchAll(PDO::FETCH_ASSOC);
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title>Reservasi Hotel</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet"/>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.2/font/bootstrap-icons.min.css"/>
    <link rel="stylesheet" href="style.css"/>
</head>
<body>
<!-- Navbar -->
<nav class="navbar navbar-expand-lg fixed-top">
    <div class="container">
        <a class="navbar-brand" href="index.php">Reservasi Hotel</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav me-auto">
                <li class="nav-item">
                    <a class="nav-link active" href="index.php">Home</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="pages/aboutUs/aboutUs.php">About Us</a>
                </li>
            </ul>
            <div class="d-flex">
                <a href="pages/login/login.php" class="btn btn-outline-primary me-2">Login</a>
                <a href="pages/registrasi/registrasi.php" class="btn btn-primary">Register</a>
            </div>
        </div>
    </div>
</nav>

<!-- Hero Section -->
<section class="hero-section">
    <div class="container">
        <h1 class="display-3 mb-4">Selamat Datang di Reservasi Hotel</h1>
        <p class="lead mb-4">Lorem, ipsum dolor sit amet consectetur adipisicing elit.</p>
        <a href="#reservasi" class="btn btn-primary btn-lg">Reservasi Sekarang</a>
    </div>
</section>

<!-- Room Types -->
<section class="py-5">
    <div class="container">
        <h2 class="text-center mb-5">Tipe Kamar</h2>
        <div class="row g-4">
            <?php foreach ($tipeKamar as $tipe): ?>
                <div class="col-md-4" data-aos="fade-up">
                    <div class="card room-card h-100">
                        <img src="assets/Tipe_<?= str_replace(' ', '_', $tipe['nama_tipe']) ?>.png"
                             class="card-img-top" alt="<?= $tipe['nama_tipe'] ?>"/>
                        <div class="card-body">
                            <h5 class="card-title"><?= $tipe['nama_tipe'] ?></h5>
                            <p class="card-text">Lorem, ipsum dolor sit amet consectetur adipisicing elit.</p>
                            <p class="text-primary fw-bold">Rp <?= number_format($tipe['biaya'], 0, ',', '.') ?>/malam</p>
                            <a href="#reservasi" class="btn btn-primary">Pesan Sekarang</a>
                        </div>
                    </div>
                </div>
            <?php endforeach; ?>
        </div>
    </div>
</section>

<!-- Reservasi -->
<section class="py-5 bg-light" id="reservasi">
    <div class="container">
        <h2 class="text-center mb-4">Formulir Reservasi</h2>

        <?php if (isset($_SESSION['success'])): ?>
            <div class="alert alert-success alert-dismissible fade show" role="alert">
                <?= $_SESSION['success'] ?>
                <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
            </div>
            <?php unset($_SESSION['success']); endif; ?>

        <?php if (isset($_SESSION['error'])): ?>
            <div class="alert alert-danger alert-dismissible fade show" role="alert">
                <?= $_SESSION['error'] ?>
                <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
            </div>
            <?php unset($_SESSION['error']); endif; ?>

        <div class="row justify-content-center">
            <div class="col-md-8">
                <div class="card">
                    <div class="card-body">
                        <form action="process_reservasi.php" method="POST">
                            <div class="mb-3">
                                <label class="form-label" for="nama_lengkap">Nama Lengkap</label>
                                <input type="text" class="form-control" name="nama_lengkap" id="nama_lengkap" required/>
                            </div>
                            <div class="mb-3">
                                <label class="form-label" for="email">Email</label>
                                <input type="email" class="form-control" name="email" id="email" required/>
                            </div>
                            <div class="mb-3">
                                <label class="form-label" for="no_telepon">No. Telepon</label>
                                <input type="tel" class="form-control" name="no_telepon" id="no_telepon" required/>
                            </div>
                            <div class="mb-3">
                                <label class="form-label" for="alamat">Alamat</label>
                                <textarea class="form-control" rows="3" name="alamat" id="alamat" required></textarea>
                            </div>
                            <div class="row">
                                <div class="col-md-6 mb-3">
                                    <label class="form-label" for="tanggal_check_in">Tanggal Check-in</label>
                                    <input type="date" class="form-control" name="tanggal_check_in"
                                           id="tanggal_check_in" required
                                           min="<?= date('Y-m-d') ?>"/>
                                </div>
                                <div class="col-md-6 mb-3">
                                    <label class="form-label" for="tanggal_check_out">Tanggal Check-out</label>
                                    <input type="date" class="form-control" name="tanggal_check_out"
                                           id="tanggal_check_out" required/>
                                </div>
                            </div>

                            <div class="mb-3">
                                <label class="form-label" for="tipe_kamar">Tipe Kamar</label>
                                <select class="form-select" name="tipe_kamar" id="tipe_kamar" required>
                                    <option value="">Pilih Tipe Kamar</option>
                                    <?php foreach ($tipeKamar as $tipe): ?>
                                        <option value="<?= $tipe['id_tipe'] ?>"
                                                data-harga="<?= $tipe['biaya'] ?>">
                                            <?= $tipe['nama_tipe'] ?> -
                                            Rp <?= number_format($tipe['biaya'], 0, ',', '.') ?>/malam
                                        </option>
                                    <?php endforeach; ?>
                                </select>
                            </div>

                            <div class="mb-3">
                                <label class="form-label" for="jumlah_kamar">Jumlah Kamar</label>
                                <input type="number" class="form-control" min="1" max="5"
                                       name="jumlah_kamar" id="jumlah_kamar" required/>
                            </div>

                            <div class="mb-3">
                                <label class="form-label" for="metode_pembayaran">Metode Pembayaran</label>
                                <select class="form-select" name="metode_pembayaran" id="metode_pembayaran" required>
                                    <option value="">Pilih Metode Pembayaran</option>
                                    <?php foreach ($metodePembayaran as $mp): ?>
                                        <option value="<?= $mp['kode_mp'] ?>"><?= $mp['nama_metode'] ?></option>
                                    <?php endforeach; ?>
                                </select>
                            </div>

                            <div class="mb-3">
                                <h5 id="total_pembayaran" class="text-primary">Total Pembayaran: Rp 0</h5>
                            </div>

                            <button type="submit" class="btn btn-primary w-100">Pesan Sekarang</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>

<!-- Footer -->
<footer class="footer">
    <div class="container">
        <div class="row">
            <div class="col-md-4 mb-4">
                <h5>Reservasi Hotel</h5>
                <p>Lorem, ipsum dolor sit amet consectetur adipisicing elit.</p>
            </div>
            <div class="col-md-4 mb-4">
                <h5>Kontak</h5>
                <p><i class="bi bi-geo-alt-fill"></i> Jl. UNJANI</p>
                <p><i class="bi bi-geo-alt-fill"></i> Jl. UNJANI</p>
                <p><i class="bi bi-geo-alt-fill"></i> Jl. UNJANI</p>
            </div>
            <div class="col-md-4 mb-4">
                <h5>Sosial Media</h5>
                <div class="d-flex gap-3">
                    <a href="#" class="text-white"><i class="bi bi-facebook fs-4"></i></a>
                    <a href="#" class="text-white"><i class="bi bi-instagram fs-4"></i></a>
                    <a href="#" class="text-white"><i class="bi bi-twitter fs-4"></i></a>
                </div>
            </div>
        </div>
        <hr class="mt-4"/>
        <div class="text-center">
            <p>&copy; 2024 Reservasi Hotel</p>
        </div>
    </div>
</footer>

</script>
<script>
    document.addEventListener('DOMContentLoaded', function() {
        const checkIn = document.getElementById('tanggal_check_in');
        const checkOut = document.getElementById('tanggal_check_out');
        const tipeKamar = document.getElementById('tipe_kamar');
        const jumlahKamar = document.getElementById('jumlah_kamar');

        // Set minimum date untuk check-in (hari ini)
        const today = new Date().toISOString().split('T')[0];
        checkIn.min = today;

        // Update minimum date untuk check-out berdasarkan check-in
        checkIn.addEventListener('change', function() {
            const selectedDate = new Date(this.value);
            const nextDay = new Date(selectedDate);
            nextDay.setDate(nextDay.getDate() + 1);

            const maxDate = new Date(selectedDate);
            maxDate.setDate(maxDate.getDate() + 30);

            checkOut.min = nextDay.toISOString().split('T')[0];
            checkOut.max = maxDate.toISOString().split('T')[0];

            if (checkOut.value && (checkOut.value <= this.value || checkOut.value > maxDate.toISOString().split('T')[0])) {
                checkOut.value = nextDay.toISOString().split('T')[0];
            }
            hitungTotalPembayaran();
        });

        checkOut.addEventListener('change', hitungTotalPembayaran);
        tipeKamar.addEventListener('change', hitungTotalPembayaran);
        jumlahKamar.addEventListener('input', hitungTotalPembayaran);

        function hitungTotalPembayaran() {
            const tipe = tipeKamar.value;
            const jumlah = jumlahKamar.value;
            const checkin = new Date(checkIn.value);
            const checkout = new Date(checkOut.value);

            if (tipe && jumlah && checkIn.value && checkOut.value) {
                const diffTime = Math.abs(checkout - checkin);
                const diffDays = Math.ceil(diffTime / (1000 * 60 * 60 * 24));
                const hargaPerMalam = Number(tipeKamar.options[tipeKamar.selectedIndex].dataset.harga);
                const total = hargaPerMalam * jumlah * diffDays;

                document.getElementById('total_pembayaran').textContent =
                    `Total Pembayaran: Rp ${total.toLocaleString('id-ID')}`;
            }
        }
    });
</script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
