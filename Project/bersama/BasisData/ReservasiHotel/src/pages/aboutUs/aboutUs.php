<?php
session_start();

if (isset($_SESSION['role']) == 'admin') {
    header("Location: ../admin/dashboard/dashboard.php");
    exit();
}

?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title>About Us - Grand Hotel Indonesia</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet"/>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.2/font/bootstrap-icons.min.css"/>
    <link rel="stylesheet" href="aboutUs.css"/>
</head>

<body>
<!-- Navbar -->
<nav class="navbar navbar-expand-lg fixed-top">
    <div class="container">
        <a class="navbar-brand" href="../../index.php">Reservasi Hotel</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav me-auto">
                <li class="nav-item">
                    <a class="nav-link" href="../../index.php">Home</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link active" href="../aboutUs/aboutUs.php">About Us</a>
                </li>
            </ul>
            <div class="d-flex">
                <a href="../login/login.php" class="btn btn-outline-primary me-2">Login</a>
                <a href="../registrasi/registrasi.php" class="btn btn-primary">Register</a>
            </div>
        </div>
    </div>
</nav>

<!-- Hero Section -->
<section class="hero-section">
    <div class="container">
        <h1 class="display-4">Tim Pengembang</h1>
        <p class="lead">Kenali Tim di Balik Website Reservasi Hotel</p>
    </div>
</section>

<!-- Team Section -->
<section class="py-5">
    <div class="container">
        <div class="row g-4 justify-content-center">
            <!-- Arya  -->
            <div class="col-md-4">
                <div class="card team-card text-center h-100">
                    <img src="../../assets/arya.jpg" class="team-img" alt="Arya Wijaya"/>
                    <div class="card-body">
                        <h5 class="card-title">Arya Wijaya</h5>
                        <p class="card-text text-muted">UI / UX Designer</p>
                        <p class="card-text">NIM: 2350081010</p>
                        <p class="card-text">Lorem ipsum dolor sit amet consectetur, adipisicing elit. Nostrum,
                            obcaecati.</p>
                        <div class="social-links">
                            <a href="#"><i class="bi bi-github"></i></a>
                            <a href="#"><i class="bi bi-linkedin"></i></a>
                            <a href="#"><i class="bi bi-instagram"></i></a>
                        </div>
                    </div>
                </div>
            </div>

            <!-- Ricky  -->
            <div class="col-md-4">
                <div class="card team-card text-center h-100">
                    <img src="../../assets/ricky.jpg" class="team-img" alt="Ricky Gunaldo"/>
                    <div class="card-body">
                        <h5 class="card-title">Ricky Gunaldo</h5>
                        <p class="card-text text-muted">Database Administrator</p>
                        <p class="card-text">NIM: 2350081028</p>
                        <p class="card-text">Lorem ipsum dolor sit amet consectetur, adipisicing elit. Nostrum,
                            obcaecati.</p>
                        <div class="social-links">
                            <a href="#"><i class="bi bi-github"></i></a>
                            <a href="#"><i class="bi bi-linkedin"></i></a>
                            <a href="#"><i class="bi bi-instagram"></i></a>
                        </div>
                    </div>
                </div>
            </div>

            <!--  Yasir  -->
            <div class="col-md-4">
                <div class="card team-card text-center h-100">
                    <img src="../../assets/YasirPhoto.jpg" class="team-img" alt="Muhamad Yasir Noval"/>
                    <div class="card-body">
                        <h5 class="card-title">Muhamad Yasir Noval</h5>
                        <p class="card-text text-muted">Backend Engineer</p>
                        <p class="card-text">NIM: 2350081004</p>
                        <p class="card-text">Lorem ipsum dolor sit amet consectetur, adipisicing elit. Nostrum,
                            obcaecati.</p>
                        <div class="social-links">
                            <a href="#"><i class="bi bi-github"></i></a>
                            <a href="#"><i class="bi bi-linkedin"></i></a>
                            <a href="#"><i class="bi bi-instagram"></i></a>
                        </div>
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

<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet"/>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
