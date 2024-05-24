<div class="container mt-5">
    <h2>Data Mahasiswa</h2>
    <?php
    $no = 1;
    if (!empty($result)) { ?>
        <?php foreach ($result as $data) { ?>
            <h4><?= $no++; ?>. <?= $data["nama"]; ?></h4>
        <?php } ?>
    <?php } else { ?>
        <h4>Tidak ada data</h4>
    <?php } ?>
</div>