<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container mt-5">
        <h4 style="margin-top: 20px;">Edit Game:</h4>
        <div class="card mt-5">
            <div class="container">
                <?php foreach ($dataGames as $data) { ?>
                    <?php if ($data['kodeGame'] == $id) { ?>
                        <div class="row pt-3">
                            <div class="col-lg-6 col-sm-12 text-center">
                                <img src="../../assets/images/game/<?= $data['image']; ?>" alt="Games" width="250"
                                     class="img-thumbnail">
                                <h5 class="pt-2"><?= $data['nameGame'] ?></h5>
                            </div>
                            <div class="col-lg-6 col-sm-12">
                                <div class="container">
                                    <!--../../routes/update_game.php-->
                                    <form action="../../routes/update_game.php" method="post" enctype="multipart/form-data">
                                        <input type="hidden" name="kodeGame" value="<?= $data['kodeGame']; ?>">
                                        <input type="hidden" name="old_image" value="<?= $data['image']; ?>">
                                        <div class="mb-3">
                                            <label for="nameGame" class="form-label">Name Game</label>
                                            <input type="text" class="form-control" id="nameGame" name="nameGame"
                                                   aria-describedby="nameGame"
                                                   value="<?= $data['nameGame'] ?>"
                                                   required>
                                            <div id="nameGame" class="form-text">For example, Blue Archive</div>
                                        </div>
                                        <div class="mb-3">
                                            <label for="image" class="form-label">Game Image</label>
                                            <input type="file" class="form-control" id="image" name="image">
                                        </div>
                                        <button type="submit" class="btn btn-primary mt-3">Update Game</button>
                                    </form>
                                </div>
                            </div>
                        </div>
                    <?php } ?>
                <?php } ?>
            </div>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>