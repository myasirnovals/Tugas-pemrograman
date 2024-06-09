<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container">
        <h4 style="margin-top: 20px;">Add Game:</h4>
        <div class="container" style="margin-top: 30px;">
            <form action="../../routes/add_game.php" method="post" enctype="multipart/form-data">
                <div class="mb-3">
                    <label for="nameGame" class="form-label">Name Game</label>
                    <input type="text" class="form-control" id="nameGame" name="nameGame" aria-describedby="nameGame"
                           required>
                    <div id="nameGame" class="form-text">For example, Blue Archive</div>
                </div>
                <div class="mb-3">
                    <label for="description" class="form-label">Description of Game</label>
                    <textarea name="description" class="form-control" id="description" cols="30" rows="10"></textarea>
                </div>
                <div class="mb-3">
                    <label for="image" class="form-label">Game Image</label>
                    <input type="file" class="form-control" id="image" name="image" required>
                </div>
                <button type="submit" class="btn btn-primary mt-5">Add Game</button>
            </form>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>