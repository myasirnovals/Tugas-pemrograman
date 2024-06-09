<?php
//konstanta Judul="Hitung Luas lingkaran"
const Judul = "Hitung Luas lingkaran";

//konstanta phi=3.14
const phi = 3.14;
echo Judul;

$r = 10;
echo "<br>Jari-jari : $r<br>" . PHP_EOL;

$luas = phi * $r * $r;
echo "Luas lingkaran = $luas";