<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container mt-5 mb-5">
        <form action="../../routes/update_profile_admin.php" method="post" enctype="multipart/form-data">
            <div class="row">
                <div class="row border text-white kartu">
                    <div class="col-md-4 col-sm-12 relative">
                        <div class="avatar">
                            <div class="avatar-bg center">
                                <?php foreach ($dataMembers as $data) { ?>
                                    <?php if ($_SESSION['memberId'] == $data['memberId']) { ?>
                                        <?php if ($data['image'] == "-") { ?>
                                            <img src="../../assets/images/member/user.png" alt="gambar profile"
                                                 class="img-thumbnail rounded-circle">
                                        <?php } else { ?>
                                            <img src="../../assets/images/member/<?= $data['image'] ?>"
                                                 alt="gambar profile"
                                                 class="img-thumbnail rounded-circle">
                                        <?php } ?>
                                    <?php } ?>
                                <?php } ?>
                            </div>
                            <br>
                        </div>
                        <input class="form-control mt-5" type="file" name="image">
                    </div>
                    <div class="col-md-8 col-sm-12">
                        <?php foreach ($dataMembers as $data) { ?>
                            <?php if ($_SESSION['memberId'] == $data['memberId']) { ?>
                                <input type="hidden" name="old_password" id="old_password"
                                       value="<?= $data['password'] ?>">
                                <input type="hidden" name="memberId" id="memberId" value="<?= $data['memberId'] ?>">
                                <input type="hidden" name="old_image" id="old_image" value="<?= $data['image'] ?>">
                                <input type="hidden" name="old_email" id="old_email" value="<?= $data['email'] ?>">
                                <input type="hidden" name="old_birthdate" id="old_birhtdate"
                                       value="<?= $data['birthdate'] ?>">
                                <h1>Profile </h1>
                                <hr>
                                <div class="row">
                                    <div class="col-sm-12 col-md-6">
                                        <div class="form-group mb-3">
                                            <label class="form-label" for="name">Nama </label>
                                            <input class="form-control" type="text" name="name" id="name"
                                                   value="<?= $data['name'] ?>">
                                        </div>
                                    </div>
                                    <div class="col-sm-12 col-md-6">
                                        <div class="form-group mb-3">
                                            <label class="form-label" for="birthdate">Tanggal Lahir </label>
                                            <input class="form-control" type="date" name="birthdate" id="birthdate"
                                                   value="<?= $data['birthdate'] ?>">
                                        </div>
                                    </div>
                                </div>
                                <div class="form-group mb-3">
                                    <label class="form-label" for="bio">Bio </label>
                                    <textarea name="bio" id="bio" cols="30" rows="5"
                                              class="form-control"><?= $data['bio'] ?></textarea>
                                </div>
                                <div class="row">
                                    <div class="col-sm-12 col-md-6">
                                        <div class="form-group mb-3">
                                            <label class="form-label" for="oe">Email Lama</label>
                                            <input class="form-control" type="email" name="oe" id="oe"
                                                   autocomplete="off"
                                                   value="<?= $data['email'] ?>"
                                                   disabled
                                            >
                                        </div>
                                    </div>
                                    <div class="col-sm-12 col-md-6">
                                        <div class="form-group mb-3">
                                            <label class="form-label" for="email">Email Baru</label>
                                            <input class="form-control" type="email" name="email" id="email"
                                                   autocomplete="off"
                                            >
                                        </div>
                                    </div>
                                    <div class="col-sm-12 col-md-12">
                                        <div class="form-group mb-3">
                                            <label class="form-label" for="password">Password</label>
                                            <input class="form-control" type="password" name="password" id="password"
                                                   autocomplete="off"
                                            >
                                        </div>
                                    </div>
                                </div>
                                <div class="form-group mb-3">
                                    <label class="form-label" for="address">Alamat </label>
                                    <textarea name="address" id="address" cols="30" rows="5"
                                              class="form-control"><?= $data['address'] ?></textarea>
                                </div>

                                <hr>
                                <div class="row">
                                    <div class="col-md-12 content-right">
                                        <button class="btn btn-primary form-btn" type="submit" name="submit">SAVE
                                        </button>
                                        <a href="user.php" class="btn btn-danger form-btn">CANCEL</a>
                                    </div>
                                </div>
                            <?php } ?>
                        <?php } ?>
                    </div>
                </div>
            </div>
        </form>
    </div>
<?php include "../layout/footer.php"; ?>