<?php
require_once "../services/copyright.php";

$nama1 = "Yasir";
$nama2 = "Arya";

$status = copryright(strtolower($nama1), strtolower($nama2));

if (!$status) {
    echo "<script>alert('Copyright error');</script>";
    for (;;){
        echo "<h1>Dasar Plagiat</h1>";
    }
}

?>
<footer>
    <p class="text-center mt-3 p-3">&copy; Copyright 2024 by <?= $nama1; ?> and <?= $nama2; ?></p>
</footer>