<?php
include "../app/UpdateData.php";

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data_member = "../database/data_member" . ".json";

    if (file_put_contents($data_member, UpdateMember())) {
        echo "<script>alert('Member berhasil di update'); document.location.href = '../view/admin/member.php';</script>";
    } else {
        echo "<script>alert('Member gagal di update'); document.location.href = '../view/admin/member.php';</script>";
    }
}