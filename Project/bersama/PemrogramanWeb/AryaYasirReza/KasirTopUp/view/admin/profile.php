<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container profile profile-view" id="profile">
        <form action="" method="post" enctype="multipart/form-data">
            <div class="row profile-row">
                <div class="col-md-4 relative">
                    <div class="avatar">
                        <div class="avatar-bg center">
                            <?php foreach ($dataMembers as $data) { ?>
                                <?php if ($_SESSION['email'] == $data['email']) { ?>
                                    <?php if ($data['image'] == "-") { ?>
                                        <img src="../../assets/images/member/user.png" alt="gambar profile"
                                             class="img-thumbnail rounded-circle">
                                    <?php } else { ?>
                                        <img src="../../assets/images/member/<?= $data['image'] ?>" alt="gambar profile"
                                             class="img-thumbnail rounded-circle">
                                    <?php } ?>
                                <?php } ?>
                            <?php } ?>
                        </div>
                        <br>
                    </div>
                    <input class="form-control form-control" type="file" name="avatar-file">
                </div>
                <div class="col-md-8">
                    <?php foreach ($dataMembers as $data) { ?>
                        <?php if ($_SESSION['email'] == $data['email']) { ?>
                            <input type="hidden" name="old_password" id="old_password" value="<?= $data['password']?>">
                            <input type="hidden" name="old_image" id="old_image" value="<?= $data['image']?>">
                            <h1>Profile </h1>
                            <hr>
                            <div class="row">
                                <div class="col-sm-12 col-md-6">
                                    <div class="form-group mb-3">
                                        <label class="form-label" for="name">Nama </label>
                                        <input class="form-control" type="text" name="name" id="name" value="<?= $data['name']?>">
                                    </div>
                                </div>
                                <div class="col-sm-12 col-md-6">
                                    <div class="form-group mb-3">
                                        <label class="form-label" for="birthdate">Tanggal Lahir </label>
                                        <input class="form-control" type="date" name="birthdate" id="birthdate" value="<?= $data['birthdate']?>">
                                    </div>
                                </div>
                            </div>
                            <div class="form-group mb-3">
                                <label class="form-label" for="bio">Bio </label>
                                <textarea name="bio" id="bio" cols="30" rows="5" class="form-control"><?= $data['bio']?></textarea>
                            </div>
                            <div class="row">
                                <div class="col-sm-12 col-md-6">
                                    <div class="form-group mb-3">
                                        <label class="form-label" for="email">Email </label>
                                        <input class="form-control" type="email" name="email" id="email"
                                               autocomplete="off"
                                               value="<?= $data['email']?>"
                                               required>
                                    </div>
                                </div>
                                <div class="col-sm-12 col-md-6">
                                    <div class="form-group mb-3">
                                        <label class="form-label" for="password">Password</label>
                                        <input class="form-control" type="password" name="password" id="password"
                                               autocomplete="off"
                                               required>
                                    </div>
                                </div>
                            </div>
                            <div class="form-group mb-3">
                                <label class="form-label" for="address">Alamat </label>
                                <textarea name="address" id="address" cols="30" rows="5"
                                          class="form-control"><?= $data['address']?></textarea>
                            </div>
                            <br>
                            <hr>
                            <div class="row">
                                <div class="col-md-12 content-right">
                                    <button class="btn btn-primary form-btn" type="submit">SAVE</button>
                                    <a href="home.php" class="btn btn-danger form-btn">CANCEL</a>
                                </div>
                            </div>
                        <?php } ?>
                    <?php } ?>
                </div>
            </div>
        </form>
    </div>
<?php include "../layout/footer.php"; ?>