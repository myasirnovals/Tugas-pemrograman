<?php include "header.php"; ?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        .style-p {
            text-align: justify;
            font-family: cambria;
        }
    </style>
</head>
<body>
<div class="container mt-5">
    <h2>HTML </h2>
   
    <p class="style-p">   
        HTML, singkatan dari HyperText Markup Language, adalah bahasa markup standar yang digunakan untuk membuat dan mendesain halaman web. HTML digunakan untuk mengatur dan memformat konten pada halaman web dengan menggunakan elemen-elemen yang ditandai dengan tag dalam bentuk kode.
        <br><br>
        Elemen-elemen HTML didefinisikan oleh tag yang ditulis dalam kurung sudut. Contoh tag umum meliputi <strong>p</strong> untuk paragraf,  <strong>h1</strong>  hingga <strong>h6</strong> <span></span> untuk heading, <strong>a</strong> untuk hyperlink, <strong>img</strong> untuk gambar, dan banyak lagi. Elemen-elemen ini dapat menggabungkan teks, gambar, video, dan bentuk interaksi lainnya untuk membuat struktur dan tampilan halaman web.
        <br><br>
        HTML juga memungkinkan integrasi dengan teknologi web lain seperti CSS (Cascading Style Sheets) untuk styling dan JavaScript untuk fungsionalitas yang ditingkatkan. Dengan CSS, pengembang dapat mendefinisikan gaya visual untuk halaman web mereka, sedangkan JavaScript memungkinkan untuk menambahkan interaktivitas, seperti menangani kejadian pengguna, memanipulasi data halaman secara dinamis, dan banyak lagi.
        <br><br>
        Dalam konteks pengembangan web, HTML bertindak sebagai kerangka kerja dasar yang menopang konten web, sedangkan teknologi lain seperti CSS dan JavaScript meningkatkan tampilan dan fungsionalitasnya.

    </p>

    <h5 class="pt-5">Contoh Table dalam bentuk HTML</h5>
    <table border="1" cellpadding="15" >
                        <thead>
                            <tr>
                                <th>Nama</th>
                                <th>Fakultas</th>
                                <th>Prodi</th>
                                <th >Kelas</th>
                            </tr>
                        </thead>
                        <tbody>
                            <tr >
                                <td>Arya Wijaya</td>
                                <td>Saint dan Informatika</td>
                                <td>Informatika</td>
                                <td>A</td>
                            </tr>
                            <tr>
                                <td>Muhamad Yasir Noval</td>
                                <td>Saint dan Informatika</td>
                                <td>Informatika</td>
                                <td>A</td>
                            </tr>
                            <tr >
                                <td>Muhamad Yusron Noval</td>
                                <td>Saint dan Informatika</td>
                                <td>Informatika</td>
                                <td>A</td>
                            </tr>
                            <tr >
                                <td>Syivana Nasywa Fadillah</td>
                                <td>Saint dan Informatika</td>
                                <td>Informatika</td>
                                <td>A</td>
                            </tr>
                           
                        </tbody>
                    </table>

    
</div>
</body>
</html>



<br><br><br>

<?php
require_once "functions.php";

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $file_name = "../../database/dataMahasiswa" . ".json";

    if (file_put_contents("$file_name", get_data())) {
        echo "success";
    } else {
        echo "There is some error";
    }
}

?>

<?php include "footer.php"; ?>
