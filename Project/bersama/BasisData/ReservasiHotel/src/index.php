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
            <!-- Standard Room -->
            <div class="col-md-4" data-aos="fade-up">
                <div class="card room-card h-100">
                    <img src="assets/Tipe_Standard.png" class="card-img-top" alt="Standard Room"/>
                    <div class="card-body">
                        <h5 class="card-title">Standard Room</h5>
                        <p class="card-text">Lorem, ipsum dolor sit amet consectetur adipisicing elit.</p>
                        <p class="text-primary fw-bold">Rp 500.000/malam</p>
                        <a href="#reservasi" class="btn btn-primary">Pesan Sekarang</a>
                    </div>
                </div>
            </div>
            <!-- Deluxe Room -->
            <div class="col-md-4" data-aos="fade-up" data-aos-delay="100">
                <div class="card room-card h-100">
                    <img src="assets/Tipe_Deluxe.png" class="card-img-top" alt="Deluxe Room"/>
                    <div class="card-body">
                        <h5 class="card-title">Deluxe Room</h5>
                        <p class="card-text">Lorem, ipsum dolor sit amet consectetur adipisicing elit.</p>
                        <p class="text-primary fw-bold">Rp 800.000/malam</p>
                        <a href="#reservasi" class="btn btn-primary">Pesan Sekarang</a>
                    </div>
                </div>
            </div>
            <!-- Suite Room -->
            <div class="col-md-4" data-aos="fade-up" data-aos-delay="200">
                <div class="card room-card h-100">
                    <img src="assets/Tipe_Suite.png" class="card-img-top" alt="Suite Room"/>
                    <div class="card-body">
                        <h5 class="card-title">Suite Room</h5>
                        <p class="card-text">Lorem, ipsum dolor sit amet consectetur adipisicing elit.</p>
                        <p class="text-primary fw-bold">Rp 1.200.000/malam</p>
                        <a href="#reservasi" class="btn btn-primary">Pesan Sekarang</a>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>

<!-- Reservasi -->
<section class="py-5 bg-light" id="reservasi">
    <div class="container">
        <h2 class="text-center mb-4">Formulir Reservasi</h2>
        <div class="row justify-content-center">
            <div class="col-md-8">
                <div class="card">
                    <div class="card-body">
                        <form>
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
                                           id="tanggal_check_in" required/>
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
                                    <option value="standard">Standard Room</option>
                                    <option value="deluxe">Deluxe Room</option>
                                    <option value="suite">Suite Room</option>
                                </select>
                            </div>
                            <div class="mb-3">
                                <label class="form-label" for="jumlah_kamar">Jumlah Kamar</label>
                                <input type="number" class="form-control" min="1" name="jumlah_kamar" id="jumlah_kamar"
                                       required/>
                            </div>
                            <div class="mb-3">
                                <label class="form-label" for="metode_pembayaran">Metode Pembayaran</label>
                                <select class="form-select" name="metode_pembayaran" id="metode_pembayaran" required>
                                    <option value="">Pilih Metode Pembayaran</option>
                                    <option value="transfer">Transfer Bank</option>
                                    <option value="kartu_kredit">Kartu Kredit</option>
                                    <option value="tunai">Cash</option>
                                </select>
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

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
