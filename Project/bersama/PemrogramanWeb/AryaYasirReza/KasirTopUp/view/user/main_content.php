<header>
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
                            <img src="../../assets/images/gameImage/slide1.jpg" class="d-block img-fluid rounded"
                                 alt="Mobile Legends">
                        </div>
                        <div class="carousel-item">
                            <img src="../../assets/images/gameImage/slide2.jpg" class="d-block img-fluid rounded"
                                 alt="Valorant">
                        </div>
                        <div class="carousel-item">
                            <img src="../../assets/images/gameImage/slide3.jpg" class="d-block img-fluid rounded"
                                 alt="Genshin Impact">
                        </div>
                    </div>
                    <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleControls"
                            data-bs-slide="prev">
                        <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                        <span class="visually-hidden">Previous</span>
                    </button>
                    <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleControls"
                            data-bs-slide="next">
                        <span class="carousel-control-next-icon" aria-hidden="true"></span>
                        <span class="visually-hidden">Next</span>
                    </button>
                </div>
            </div>
        </div>

    </div>
</section>
<br>
<hr>

<!-- -------------------------------Top UP-------------------------------- -->

<section id="populer" class="populer py-4">
    <div class="container">
        <h1 class="text-center mb-4">GAMES</h1>
        <div class="row justify-content-center">
            <?php if (!empty($dataGames)) { ?>
                <?php foreach ($dataGames as $data) { ?>
                    <div class="col-md-2 ">
                        <div class="text-center gambar">
                            <a href="#harga-ml">
                                <img src="../../assets/images/gameImage/mlbb.jpg" alt="Mobile Legend"
                                     class="text-center">
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
                                        <button style="color: var(--green);" class="btn my-2 " type="button">Pesan
                                            Sekarang
                                        </button>
                                    </a>
                                </div>
                            </div>
                        </div>

                    </div>
                <?php } ?>
            <?php } else { ?>
                <div class="col-md-12 col-sm-12">
                    <div class="text-center gambar">
                        <div class="fs-4 text-white">Game Belum Ditambahkan</div>
                    </div>
                </div>
            <?php } ?>
        </div>
    </div>
</section>