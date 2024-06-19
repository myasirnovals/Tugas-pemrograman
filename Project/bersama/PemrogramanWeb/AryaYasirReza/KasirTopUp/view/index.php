<<<<<<< HEAD
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=, initial-scale=1.0">
    <!-- link bootstrap -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <!-- link css -->
     <link rel="stylesheet" href="kasir.css">
    <!-- link font -->
    
    <title>Kasir Top Up Game</title>
</head>
<body>
    <header >
        <nav class="navbar navbar-expand-lg header ">
            <div class="container-fluid justify-content-center">
                <a class="navbar-brand title fs-4" style="color: var(--green);" href="#">Kasir Game</a>
            </div>
        </nav>
    </header>

<!-- -----------------------------------Carousel------------------------------------ -->
    <section class="pt-5 ">
        <div class="container">
            <div class="row justify-content-center">
                <div class="col-8 ">
                    <div id="carouselExampleControls" class="carousel slide" data-bs-ride="carousel">
                    <div class="carousel-inner">
                        <div class="carousel-item active">
                        <img src="../assets/images/game/slide1.jpg" class="d-block img-fluid rounded" alt="Mobile Legends">
                        </div>
                        <div class="carousel-item">
                        <img src="../assets/images/game/slide2.jpg" class="d-block img-fluid rounded"  alt="Valorant">
                        </div>
                        <div class="carousel-item">
                        <img src="../assets/images/game/slide3.jpg" class="d-block img-fluid rounded"  alt="Genshin Impact">
                        </div>
                    </div>
                    <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleControls" data-bs-slide="prev">
                        <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                        <span class="visually-hidden">Previous</span>
                    </button>
                    <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleControls" data-bs-slide="next">
                        <span class="carousel-control-next-icon" aria-hidden="true"></span>
                        <span class="visually-hidden">Next</span>
                    </button>
                    </div>
                </div>
            </div>

        </div>
    </section>
    <br>
    <hr >

    <!-- -------------------------------Top UP-------------------------------- -->
    
    <section id="populer" class="populer py-4">
        <div class="container">
                <h1 class="text-center mb-4">GAMES</h1>
                <div class="row justify-content-center">
                    <div class="col-md-2 ">
                        <div class="text-center gambar">
                            <a href="#harga-ml">
                                    <img src="../assets/images/game/mlbb.jpg" alt="Mobile Legend" class="text-center">
                                    <div class="fs-4 text-white">Mobile Legends</div>
                            </a>
                        </div>
                        <div class="overlay" id="harga-ml">
                            <div class="popup">
                                <h2>HARGA MOBILE LEGENDS</h2>
                                <a class="close" href="#populer">&times;</a>
                                <br>
                                <div class="content">
                                    <select class="form-select" aria-label="Default select example">
                                        <option selected>Pilih Diamonds</option>
                                        <option value="1">400 Diamonds: 100K</option>
                                        <option value="2">568 Diamonds: 140K</option>
                                        <option value="3">2010 Diamonds: 475K</option>
                                        <option value="3">4830 Diamonds: 1140K</option>
                                    </select>
                                    <a href="">
                                        <button style="color: var(--green);" class="btn my-2 "   type="button" >Pesan Sekarang</button>
                                    </a>
                                </div>
                            </div>
                        </div>

                    </div>
                    <div class="col-md-2 ">
                        <div class="text-center gambar">
                            <a href="#harga-valo">
                                    <img src="../assets/images/game/valorant.jpg" alt="Mobile Legend" class="text-center">
                                    <div class="fs-4 text-white">Valorant</div>
                            </a>
                        </div>
                        <div class="overlay" id="harga-valo">
                            <div class="popup">
                                <h2>HARGA VALORANT</h2>
                                <a class="close" href="#populer">&times;</a>
                                <br>
                                <div class="content">
                                    <select class="form-select" aria-label="Default select example">
                                        <option selected>Pilih Valorant Point</option>
                                        <option value="1">2400 Vp: 225K</option>
                                        <option value="2">4000 Vp: 360K</option>
                                        <option value="3">8150 Vp: 720K</option>
                                    </select>
                                    <a href="">
                                        <button style="color: var(--green);" class="btn my-2 "   type="button" >Pesan Sekarang</button>
                                    </a>
                                </div>
                            </div>
                        </div>

                    </div>
                    <div class="col-md-2 ">
                        <div class="text-center gambar">
                            <a href="#harga-gsi">
                                    <img src="../assets/images/game/GenshinImpact.jpg" alt="Mobile Legend" class="text-center">
                                    <div class="fs-4 text-white">Genshin Impact</div>
                            </a>
                        </div>
                        <div class="overlay" id="harga-gsi">
                            <div class="popup">
                                <h2>HARGA GENSHIN IMPACT</h2>
                                <a class="close" href="#populer">&times;</a>
                                <br>
                                <div class="content">
                                    <select class="form-select" aria-label="Default select example">
                                        <option selected>Pilih Genesis Crystal</option>
                                        <option value="1">330 Gc: 72K</option>
                                        <option value="2">1090 Gc: 230K</option>
                                        <option value="3">2240 Gc: 440K</option>
                                        <option value="3">8080 Gc: 1450K</option>
                                    </select>
                                    <a href="">
                                        <button style="color: var(--green);" class="btn my-2 "   type="button" >Pesan Sekarang</button>
                                    </a>
                                </div>
                            </div>
                        </div>

                    </div>
                </div>
            </div>    
    </section>


    <!-- --------------------------About Us---------------------------------- -->

    <section class="py-5">
        <div class="container">
            <div class="row justify-content-center">
                <div class="col-md-4 d-grid justify-content-center">
                    <div class="card text-white kartu"  style="width: 28rem;">
                        <div class="card-header" style="background-color: var(--dark-blue);">
                            <h3 class="card-title fs-3 text-center " style="color: var(--green);" >About Us</h3>
                        </div>
                        <div class="card-body">
                                
                                    <h4 >Arya Wijaya</h4>
                                        <p class="card-text">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Est, dolore.</p>
                                        <br>
                                    <h4 >Muhammad Yasri Noval</h4>
                                        <p class="card-text">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Est, dolore.</p>
                                        <br>
                                    <h4 >Reza...</h4>
                                        <p class="card-text">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Est, dolore.</p>
                                    
                                
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- -------------------------foooter-------------------------------- -->
    <footer>
        <div id="copyright">
            &copy;AryaYasirReza
        </div>
    </footer>


    
    <!-- link js -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
=======
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Top Up Store</title>
</head>
<body>
<?php
session_start();

if(!isset($_SESSION["logged"])) {
    header("Location: user/user.php");
    exit();
}
?>
>>>>>>> abab1daa3ba3c9c7cb1518501971e33318ef7b76
</body>
</html>