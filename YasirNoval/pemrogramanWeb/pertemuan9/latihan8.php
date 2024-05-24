<?php
    $teks1= "Aku Sedang Belajar ";
    $teks2="Pemograman Web";
    $teks3="PHP 4";
    $hasil= $teks1 . $teks2 . $teks3;
    printf("hasil : %s<BR>\n", $hasil);
    $hasil= $teks1 . "" . $teks2 . "" . $teks3;
    printf("hasil : %s<BR>\n", $hasil);
?>