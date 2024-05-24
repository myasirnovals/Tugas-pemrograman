<?php include "header.php"; ?>

<div class="container mt-5">
    <h2>Tambah Mahasiswa</h2>
    <form action="form.php" method="post" enctype="multipart/form-data">
        <div class="card">
            <div class="card-body">
                <div class="row">
                    <div class="col-6">
                        <div class="mb-3">
                            <label for="nama" class="form-label">Nama: </label>
                            <input class="form-control" type="text" name="nama" id="nama" required>
                        </div>
                        <div class="mb-3">
                            <label for="nim" class="form-label">Nim: </label>
                            <input class="form-control" type="text" name="nim" id="nim" pattern="[0-9]{10}" required>
                        </div>
                        <div class="mb-3">
                            <label for="kelas" class="form-label">Kelas: </label>
                            <input class="form-control" type="text" name="kelas" id="kelas" pattern="[A-Z]{1}" required>
                        </div>
                        <div class="mb-3">
                            <label for="angkatan" class="form-label">Angkatan</label>
                            <select name="angkatan" id="angkatan" class="form-select">
                                <?php for ($year = 2020; $year <= $today; $year++) { ?>
                                    <?php if ($year === $today) { ?>
                                        <option value="<?= $year; ?>" selected> <?= $year; ?></option>
                                    <?php } else { ?>
                                        <option value="<?= $year; ?>"> <?= $year; ?></option>
                                    <?php } ?>
                                <?php } ?>
                            </select>
                        </div>
                        <div class="mb-3">
                            <label for="deskripsi" class="form-label">Deskripsi singkat: </label>
                            <textarea class="form-control" name="deskripsi" id="deskripsi" cols="30"
                                      rows="5"></textarea>
                        </div>
                        <div class="mb-5">
                            <label for="gambar" class="form-label">Upload Profile: </label>
                            <input class="form-control" type="file" name="gambar" id="gambar">
                        </div>
                        <div class="mb-3">
                            <input type="submit" class="btn btn-success" value="submit" name="submit">
                            <button class="btn btn-danger text-white" type="reset">Reset</button>
                        </div>
                    </div>
                    <div class="col-6 text-center">
                        <img class="img-fluid mt-5" src="../../assets/img/logoUnjani-removebg-preview.png" alt="">
                        <h3 class="mt-5">Universitas Jenderal Achmad Yani</h3>
                    </div>
                </div>
            </div>
        </div>
    </form>
</div>
<br><br><br>

<?php
require_once "functions.php";

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $file_name = "../../database/dataMahasiswa" . ".json";

    if (file_put_contents("$file_name", get_data())) {
        echo "success";
    } else {
        echo "There is some error";
    }
}

?>

<?php include "footer.php"; ?>
