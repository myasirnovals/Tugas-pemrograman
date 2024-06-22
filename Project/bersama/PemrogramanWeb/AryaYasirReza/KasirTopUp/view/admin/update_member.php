<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container mt-5">
        <h4 style="color: var(--green); margin-top: 20px;">Edit user:</h4>
        <div class="card mt-5 text-white kartu">
            <div class="container">
                <?php foreach ($dataMembers as $data) { ?>
                    <?php if ($data['memberId'] == $id) { ?>
                        <div class="row pt-3">
                            <div class="col-lg-12 col-sm-12">
                                <div class="container">
                                    <form action="../../routes/update_member.php" method="post">
                                        <input type="hidden" name="memberId" value="<?= $data['memberId']; ?>">
                                        <input type="hidden" name="old_phone" value="<?= $data['phone']; ?>">
                                        <input type="hidden" name="old_username" value="<?= $data['username']; ?>">
                                        <div class="mb-3">
                                            <label for="name" class="form-label">Nama</label>
                                            <input type="text" class="form-control" id="name" name="name"
                                                   value="<?= $data['name'] ?>"
                                                   disabled
                                                   required>
                                        </div>
                                        <div class="row">
                                            <div class="col-md-6 col-sm-12 mb-3">
                                                <label for="ou" class="form-label">Username lama</label>
                                                <input type="text" class="form-control" id="ou"
                                                       name="ou"
                                                       value="<?= $data['username'] ?>"
                                                       disabled
                                                >
                                            </div>
                                            <div class="col-md-6 col-sm-12 mb-3">
                                                <label for="username" class="form-label">Username baru</label>
                                                <input type="text" class="form-control" id="username"
                                                       name="username"
                                                >
                                            </div>
                                        </div>
                                        <div class="row">
                                            <div class="col-md-6 col-sm-12 mb-3">
                                                <label for="op" class="form-label">Telepon lama</label>
                                                <input type="text" class="form-control" id="op"
                                                       name="op"
                                                       value="<?= $data['phone'] ?>"
                                                       disabled
                                                >
                                            </div>
                                            <div class="col-md-6 col-sm-12 mb-3">
                                                <label for="phone" class="form-label">Telepon baru</label>
                                                <input type="text" class="form-control" id="phone"
                                                       name="phone"
                                                >
                                            </div>
                                        </div>
                                        <div class="mb-3">
                                            <label for="members" class="form-label">Member Group:</label>
                                            <select name="members" id="members" class="form-control">
                                                <?php if ($data['members'] == "admin") { ?>
                                                    <option value="admin" selected>Admin</option>
                                                    <option value="silver">Silver</option>
                                                    <option value="gold">Gold</option>
                                                    <option value="platinum">Platinum</option>
                                                <?php } else if ($data['members'] == "silver") { ?>
                                                    <option value="admin">Admin</option>
                                                    <option value="silver" selected>Silver</option>
                                                    <option value="gold">Gold</option>
                                                    <option value="platinum">Platinum</option>
                                                <?php } else if ($data['members'] == "gold") { ?>
                                                    <option value="admin">Admin</option>
                                                    <option value="silver">Silver</option>
                                                    <option value="gold" selected>Gold</option>
                                                    <option value="platinum">Platinum</option>
                                                <?php } else if ($data['members'] == "platinum") { ?>
                                                    <option value="admin">Admin</option>
                                                    <option value="silver">Silver</option>
                                                    <option value="gold">Gold</option>
                                                    <option value="platinum" selected>Platinum</option>
                                                <?php } ?>
                                            </select>
                                        </div>
                                        <button type="submit" class="btn btn-primary mt-3 mb-4">Update Member</button>
                                    </form>
                                </div>
                            </div>
                        </div>
                    <?php } ?>
                <?php } ?>
            </div>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>