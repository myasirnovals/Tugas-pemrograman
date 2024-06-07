<?php
//konstanta Judul="Hitung Luas lingkaran"
const Judul = "Hitung Luas lingkaran";

//konstanta phi=3.14
const phi = 3.14;

echo Judul;
$r = 10;
echo "<BR>Jari-jari : $r<BR>\n";

$luas = phi * $r * $r;
echo "Luas lingkaran = $luas";