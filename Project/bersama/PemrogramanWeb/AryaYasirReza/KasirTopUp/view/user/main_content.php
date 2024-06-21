    

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
                    <div class="col-lg-2 col-md-4 col-sm-12 mt-3">
                        <div class="text-center gambar">
                            <a href="detail_product.php?id=<?= $data['gameId']; ?>">
                                <img src="../../assets/images/game/<?= $data['image']; ?>" alt="game"
                                     class="text-center">
                                <div class="fs-4 text-white"><?= $data['gameName']; ?></div>
                            </a>
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