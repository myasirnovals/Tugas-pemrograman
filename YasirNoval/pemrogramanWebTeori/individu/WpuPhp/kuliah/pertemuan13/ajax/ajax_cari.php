<?php
require_once "../functions.php";

$students = cari($_GET['keyword']);
?>

<?php
$no = 1;
if (!empty($students)) {
    ?>
    <table class="table table-bordered">
        <thead>
        <tr>
            <th>No</th>
            <th>Gambar</th>
            <th>Nama</th>
            <th>Aksi</th>
        </tr>
        </thead>
        <?php if (!empty($students)) { ?>
            <tbody>
            <?php foreach ($students as $student) { ?>
                <tr>
                    <td><?= $no++; ?></td>
                    <td>
                        <img src="../../image/<?= $student['gambar']; ?>" alt="Gambar"
                             class="img-thumbnail w-50">
                    </td>
                    <td><?= $student['nama']; ?></td>
                    <td>
                        <a href="detail.php?id=<?= $student['id']; ?>" class="btn btn-outline-success">Lihat
                            detail</a>
                    </td>
                </tr>
            <?php } ?>
            </tbody>
        <?php } else { ?>
            <tbody>
            <tr>
                <td colspan="4" style="color: red; text-align: center; font-style: italic"><p>Data Siswa Tidak
                        Ditemukan!</p></td>
            </tr>
            </tbody>
        <?php } ?>
    </table>
<?php } ?>