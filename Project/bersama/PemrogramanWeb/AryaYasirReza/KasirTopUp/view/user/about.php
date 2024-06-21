<?php include "../layout/header.php"; ?>
<?php $member = "member";
include "nav_bar.php"; ?>
    <div class="container py-4 py-xl-5">
        <div class="row mb-5">
            <div class="col-md-8 col-xl-6 text-center mx-auto">
                <h2 style="color: var(--green);">Our Team</h2>
                <p class="w-lg-50">Tujuan dan maksud dari kami untuk membuat website ini adalah untuk memenuhi salah
                    satu tugas dari mata kuliah praktikum pemrograman web.</p>
            </div>
        </div>
        <div class="row gy-4 row-cols-1 row-cols-md-2 row-cols-lg-3">
            <?php foreach ($dataMembers as $data) { ?>
                <?php if (
                    $data['memberId'] == "6671dcad0f079" ||
                    $data['memberId'] == "6673d94bf37e4" ||
                    $data['memberId'] == "6673d9722e552"
                ) { ?>
                    <div class="col">
                        <div class="card text-white kartu">
                            <div class="card-body d-flex align-items-center p-0">
                                <?php if ($data['image'] == "-") { ?>
                                    <img class="rounded-circle flex-shrink-0 me-3 fit-cover" width="130" height="130"
                                         src="../../assets/images/member/user.png"
                                         alt="profile">
                                <?php } else { ?>
                                    <img class="rounded-circle flex-shrink-0 me-3 fit-cover" width="130" height="130"
                                         src="../../assets/images/member/<?= $data['image']; ?>"
                                         alt="profile">
                                <?php } ?>
                                <div>
                                    <h5 class="fw-bold text-primary mb-0"><?= $data['name']; ?></h5>
                                    <p class="text-white mb-1 mt-2"><?= $data['bio'] ?></p>
                                </div>
                            </div>
                        </div>
                    </div>
                <?php } ?>
            <?php } ?>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>