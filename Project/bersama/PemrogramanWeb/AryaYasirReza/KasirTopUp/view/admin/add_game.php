<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container">
        <h4 style="color: var(--green); margin-top: 20px;">Add Game:</h4>
        <div class="container" style="margin-top: 30px;">
            <div class="card mb-5 text-white kartu">
                <form action="../../routes/add_game.php" method="post" enctype="multipart/form-data">
                    <div class="row">
                        <div class="col-6">
                            <div class="mb-3">
                                <label for="gameName" class="form-label">Name Game</label>
                                <input type="text" class="form-control" id="gameName" name="gameName"
                                       aria-describedby="gameName"
                                       required>
                                <div id="gameName" class="form-text text-white">For example, Blue Archive</div>
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
            </div>
            <div class="container" style="margin-top: 20px;">
                <h4 class="text-center" style="color: var(--green);">Daftar Game</h4>
                <?php
                if (!empty($dataGames)) {
                    $no = 1;
                    ?>
                    <table class="table table-bordered table-dark table-striped table-responsive mt-5">
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
                                <td class="text-center"><img src="../../assets/images/game/<?= $data['image']; ?>" alt="Games" width="250"
                                         class="img-thumbnail"></td>
                                <td><?= $data['gameName']; ?></td>
                                <td class="text-center">
                                    <a href="update_game.php?id=<?= $data['gameId']; ?>"
                                       class="btn btn-primary">Edit</a>
                                    <a href="../../routes/delete_game.php?id=<?= $data['gameId']; ?>"
                                       class="btn btn-danger">Hapus</a>
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