<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container mt-5">
        <h4 style="color: var(--green); margin-top: 20px;">Edit Game:</h4>
        <div class="card mt-5 text-white kartu">
            <div class="container">
                <?php foreach ($dataGames as $data) { ?>
                    <?php if ($data['gameId'] == $id) { ?>
                        <div class="row pt-3">
                            <div class="col-lg-6 col-sm-12 text-center">
                                <img src="../../assets/images/game/<?= $data['image']; ?>" alt="Games" width="250"
                                     class="img-thumbnail">
                                <h5 class="pt-2"><?= $data['gameName'] ?></h5>
                            </div>
                            <div class="col-lg-6 col-sm-12">
                                <div class="container">
                                    <form action="../../routes/update_game.php" method="post" enctype="multipart/form-data">
                                        <input type="hidden" name="gameId" value="<?= $data['gameId']; ?>">
                                        <input type="hidden" name="old_image" value="<?= $data['image']; ?>">
                                        <div class="mb-3">
                                            <label for="gameName" class="form-label">Name Game</label>
                                            <input type="text" class="form-control" id="gameName" name="gameName"
                                                   aria-describedby="gameName"
                                                   value="<?= $data['gameName'] ?>"
                                                   required>
                                            <div id="gameName" class="form-text text-white">For example, Blue Archive</div>
                                        </div>
                                        <div class="mb-3">
                                            <label for="image" class="form-label">Game Image</label>
                                            <input type="file" class="form-control" id="image" name="image">
                                        </div>
                                        <button type="submit" class="btn btn-primary mt-3 mb-4">Update Product</button>
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