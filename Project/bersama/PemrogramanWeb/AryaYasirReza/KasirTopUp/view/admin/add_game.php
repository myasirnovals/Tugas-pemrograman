<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container">
        <h4 style="margin-top: 20px;">Add Game:</h4>
        <div class="container" style="margin-top: 30px;">
            <form action="../../routes/add_game.php" method="post" enctype="multipart/form-data">
                <div class="row">
                    <div class="col-6">
                        <div class="mb-3">
                            <label for="nameGame" class="form-label">Name Game</label>
                            <input type="text" class="form-control" id="nameGame" name="nameGame"
                                   aria-describedby="nameGame"
                                   required>
                            <div id="nameGame" class="form-text">For example, Blue Archive</div>
                        </div>
                    </div>
                    <div class="col-6">
                        <div class="mb-3">
                            <label for="image" class="form-label">Game Image</label>
                            <input type="file" class="form-control" id="image" name="image" required>
                        </div>
                    </div>
                </div>
                <button type="submit" class="btn btn-primary mt-3">Add Game</button>
            </form>
            <div class="container" style="margin-top: 20px;">
                <h4 class="text-center">Daftar Game</h4>
                <?php
                if (!empty($dataGames)) {
                    $no = 1;
                    ?>
                    <table class="table table-bordered mt-5">
                        <thead>
                        <tr class="text-center">
                            <th>No</th>
                            <th>Gambar</th>
                            <th>Nama Game</th>
                            <th>Aksi</th>
                        </tr>
                        </thead>
                        <tbody>
                        <?php foreach ($dataGames as $data) { ?>
                            <tr>
                                <td><?= $no++; ?></td>
                                <td>-</td>
                                <td><?= $data['nameGame']; ?></td>
                                <td class="text-center">
                                    <a href="update_game.php?id=<?= $data['kodeGame']; ?>"
                                       class="btn btn-primary">Edit</a>
                                    <a href="#" class="btn btn-danger">Hapus</a>
                                </td>
                            </tr>
                        <?php } ?>
                        </tbody>
                    </table>
                <?php } else { ?>
                    <p class="text-center">Game belum ditambahkan</p>
                <?php } ?>
            </div>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>