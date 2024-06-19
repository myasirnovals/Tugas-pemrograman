<div class="container">
    <?php if (!empty($dataGames)) { ?>
        <div class="row">
            <div class="col-md-12 col-sm-12">
                <h2 style="font-size: 30px;margin: 0;padding-top: 20px;text-shadow: 2px 2px 3px;text-align: center;">
                    Selamat Datang di Toko TopUp Game</h2>
                <h3 style="font-size: 25px;margin: 0;padding: 20px;text-shadow: 2px 2px 3px;text-align: center;">
                    Select Your Game</h3>
            </div>
        </div>
        <div class="row">
            <?php foreach ($dataGames as $data) { ?>
                <div class="col-md-3">
                    <div class="card" style="margin: 10px;">
                        <div class="card-body" style="text-align: center;">
                            <h4 class="card-title" style="font-size: 20px;"><?= $data['gameName']; ?></h4>
                            <h6 class="text-muted card-subtitle mb-2">Subtitle</h6>
                            <picture><img src="../../assets/images/game/<?= $data['image']; ?>" alt="gambar game" class="img-thumbnail"></picture>
                            <a href="detail_product.php?id=<?= $data['gameId']; ?>" class="btn btn-primary" type="button" style="padding: 6px 25%;margin: 15px;">Select
                            </a>
                        </div>
                    </div>
                </div>
            <?php } ?>
        </div>
    <?php } else { ?>
        <div class="row">
            <div class="col-md-12 col-sm-12">
                <h1 style="font-size: 25px;margin: 0;padding: 20px;text-shadow: 2px 2px 3px;text-align: center;">
                    Maaf Game Belum ditambahkan oleh Admin
                </h1>
            </div>
        </div>
    <?php } ?>
</div>