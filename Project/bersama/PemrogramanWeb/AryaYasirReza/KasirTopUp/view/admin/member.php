<?php include "../layout/header.php"; ?>
<?php include "nav_bar.php"; ?>
    <div class="container">
        <h4 style="color: var(--green); margin-top: 20px;">Members</h4>
        <div class="container" style="margin-top: 10px;">
            <?php
            if (!empty($dataMembers)) {
                $no = 1;
                ?>
                <table class="table table-bordered table-dark table-striped table-responsive mt-5">
                    <thead>
                    <tr class="text-center">
                        <th>No</th>
                        <th>Nama</th>
                        <th>Email</th>
                        <th>username</th>
                        <th>member</th>
                        <th>telephone</th>
                        <th>address</th>
                        <th>Aksi</th>
                    </tr>
                    </thead>
                    <tbody>
                    <?php foreach ($dataMembers as $data) { ?>
                        <tr>
                            <td><?= $no++; ?></td>
                            <td><?= $data['name']; ?></td>
                            <td><?= $data['email']; ?></td>
                            <td><?= $data['username']; ?></td>
                            <td><?= $data['members']; ?></td>
                            <td><?= $data['phone']; ?></td>
                            <td><?= $data['address']; ?></td>
                            <td class="text-center">
                                <a href="update_member.php?id=<?= $data['memberId'] ?>"
                                   class="btn btn-primary">Edit</a>
                                <?php if (
                                    ($data['members'] != 'admin')
                                ) { ?>
                                    <a href="../../routes/delete_member.php?id=<?= $data['memberId']; ?>"
                                       class="btn btn-danger">Hapus</a>
                                <?php } ?>
                            </td>
                        </tr>
                    <?php } ?>
                    </tbody>
                </table>
            <?php } else { ?>
                <p class="text-center">Member belum ditambahkan</p>
            <?php } ?>
        </div>
    </div>
<?php include "../layout/footer.php"; ?>