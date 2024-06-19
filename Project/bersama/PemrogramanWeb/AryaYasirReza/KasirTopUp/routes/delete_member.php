<?php
include "../app/DeleteData.php";

$data_member = "../database/data_member" . ".json";

if (file_put_contents($data_member, DeleteMember())) {
    echo "<script>alert('Member berhasil di hapus'); document.location.href = '../view/admin/member.php';</script>";
} else {
    echo "<script>alert('Game gagal di hapus'); document.location.href = '../view/admin/member.php';</script>";
}