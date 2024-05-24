<?php
    if (isset($_POST['submit'])){ // cek apakah tombol submit telah diklik
        $name=$_POST['name']; //ambil nilai dari input name
        $email=$_POST['email']; //ambil nilai input email
        $message=$_POST['message']; //ambil nilai input massege

        //proses data yang telah diterima
        //misalnya, simpan data ke dalam databese atau email 

        echo ("Data telah berhasil dikirim!");

    }
    ?>