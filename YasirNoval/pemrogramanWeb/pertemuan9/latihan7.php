<?php 
    $bil=100;
    $bil2=20;

    $teks="PHP";
    $teks2="php";

    $hasil=($bil <> $bil2) or ($teks == $teks2);
    printf("(%d <> %d) or (%s == %s ) adalah %d<Br>\n", $bil,$bil2, $teks,$teks2,$hasil);
    $hasil = ! ($teks == $teks2);
    printf("!(%s == %s) adalah %d<Br>\n", $teks,$teks2,$hasil);

?>