<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container">
        <h4 style="color: var(--green); margin-top: 20px;">Add Product:</h4>
        <div class="container" style="margin-top: 10px;">
            <div class="card mt-5 text-white kartu">
                <form action="../../routes/add_product.php" method="post" enctype="multipart/form-data">
                    <div class="mb-3">
                        <label for="name" class="form-label">Product name</label>
                        <input type="text" class="form-control" id="name" name="name" aria-describedby="name" required>
                        <div id="name" class="form-text text-white">For example, 60 Genesis Crystals.</div>
                    </div>
                    <div class="mb-3">
                        <label for="price" class="form-label">Product Price</label>
                        <input type="text" class="form-control" id="price" name="price" required>
                    </div>
                    <div class="mb-3">
                        <label for="bonus" class="form-label">Product Bonus</label>
                        <input type="text" class="form-control" id="bonus" name="bonus" aria-describedby="bonus">
                        <div id="bonus" class="form-text text-white">For example, +60 bonus! Genesis Crystals.</div>
                    </div>
                    <div class="mb-3">
                        <label for="fromGame" class="form-label">From What Game</label>
                        <select class="form-select" aria-label="fromGame" name="gameCode" required>
                            <?php if (!empty($dataGames)) { ?>
                                <?php foreach ($dataGames as $data) { ?>
                                    <option value="<?= $data['gameId']; ?>"><?= $data['gameName']; ?></option>
                                <?php } ?>
                            <?php } else { ?>
                                <option value="0" selected>Open this select menu</option>
                            <?php } ?>
                        </select>
                    </div>
                    <div class="mb-3">
                        <label for="image" class="form-label">Product Image</label>
                        <input type="file" class="form-control" id="image" name="image" required>
                    </div>
                    <button type="submit" class="btn btn-primary mt-5">Submit</button>
                </form>
            </div>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>