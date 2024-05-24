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
    <h2>PHP </h2>
   
    <p class="style-p">   
       
        PHP (Hypertext Preprocessor) adalah bahasa pemrograman script server-side yang banyak digunakan untuk mengembangkan situs web dan aplikasi web. PHP dirancang khusus untuk pengembangan web, memungkinkan pengembang untuk menulis skrip yang dijalankan di server web untuk menghasilkan konten dinamis sebelum halaman web dikirim ke browser pengguna.
        <br><br>
        Kelebihan utama PHP adalah kemampuannya untuk berinteraksi dengan database, seperti MySQL, Oracle, dan PostgreSQL. Ini memungkinkan pembuatan aplikasi web yang kompleks dan dinamis yang dapat menyimpan dan mengambil informasi dari database untuk manipulasi atau display. Misalnya, PHP sering digunakan untuk membangun sistem manajemen konten, forum online, dan toko e-commerce.
        <br><br>
        PHP dapat dengan mudah disisipkan ke dalam HTML. Ini sering dilakukan dengan menempatkan kode PHP di antara tag khusus yang memungkinkan server untuk memprosesnya sebelum mengirim halaman tersebut ke browser. Sebagai contoh, PHP sering digunakan untuk menambahkan elemen-elemen seperti formulir yang diproses, informasi pengguna, dan data lainnya yang dinamis ke dalam halaman web statis.
    </p>

    <h5 class="pt-5">Contoh Table </h5>
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
