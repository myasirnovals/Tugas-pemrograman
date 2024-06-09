<?php
if (isset($_POST['submit'])) {
    $number = $_POST['bil1'];
    $number2 = $_POST['bil2'];

    printf("<h2><b>Hitung Sisa Pembagian<br></h2></b>\n<hr>\n");

    $result = $number % $number2;
    echo $number . " % " . $number2 . " = " . $result;
}


    