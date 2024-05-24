


<?php
    if (isset($_POST['submit'])){ //cek apakah tombol submit telah diklik
        $number=$_POST['number']; //ambil nilai dari input name
        $number2=$_POST['number2']; //ambil nilai input email

        //proses data yang telah diterima
        //misalnya, simpan data ke dalam databese atau email 
        printf("<h2><B>Hitung Sisa Pembagian<Br></h2></B>\n<hr></hr>\n");
         $hasil= $number % $number2;
         echo ("$number % $number2=$hasil");
        

    }
    ?>

    