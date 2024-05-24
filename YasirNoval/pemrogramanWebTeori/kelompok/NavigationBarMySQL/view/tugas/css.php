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


        /*----------------------------------------------------------------------------------- */

        .styled-table {
            border-collapse: collapse;
            margin: 25px 0;
            font-size: 0.9em;
            font-family: sans-serif;
            min-width: 400px;
            box-shadow: 0 0 20px rgba(0, 0, 0, 0.15);
        }

        .styled-table thead tr {
            background-color: #009879;
            color: #ffffff;
            text-align: left;
        }

        .styled-table th,
        .styled-table td {
            padding: 12px 15px;
        }


        .styled-table tbody tr {
            border-bottom: 1px solid #dddddd;
        }

        .styled-table tbody tr:nth-of-type(even) {
            background-color: #f3f3f3;

        }

        .styled-table tbody tr:last-of-type {
            border-bottom: 2px solid #009879;

        }


        .styled-table tbody tr.active-row {
            font-weight: bold;
            color: #009879;

        }


        .styled-table tbody tr:nth-of-type(even).active-row {
            font-weight: bold;
            color: #228B22;
        }


    </style>
</head>
<body>
<div class="container mt-5">
    <h2>CSS </h2>

    <p class="style-p">
        CSS (Cascading Style Sheets) adalah bahasa yang digunakan untuk mendesain dan mengatur tampilan halaman web. CSS
        memungkinkan pengembang untuk mengontrol berbagai aspek tampilan suatu elemen HTML, termasuk warna, font,
        ukuran, jarak, dan posisi. Dengan menggunakan CSS, pengembang bisa mengatur tampilan dan layout dari berbagai
        elemen di dalam dokumen HTML tanpa harus mengubah konten atau struktur HTML itu sendiri.
        <br><br>

        CSS diperkenalkan untuk memisahkan konten dari desain, memudahkan pemeliharaan, mengurangi kompleksitas, dan
        meningkatkan fleksibilitas dalam presentasi konten. CSS bekerja dengan memilih elemen berdasarkan selector
        (seperti tag, class, atau ID) dan kemudian menerapkan satu atau lebih deklarasi gaya ke elemen tersebut.
        <br><br>

        Secara keseluruhan, CSS adalah alat yang sangat kuat dan esensial dalam pengembangan web yang tidak hanya
        meningkatkan efisiensi tetapi juga memperkaya pengalaman pengguna dengan memberikan tampilan yang lebih menarik
        dan konsisten di berbagai perangkat dan browser.
    </p>


    <h5 class="pt-5">Contoh Table dalam bentuk CSS</h5>
    <table class="styled-table">
        <thead>
        <tr>
            <th>Nama</th>
            <th>Fakultas</th>
            <th>Prodi</th>
            <th>Kelas</th>
        </tr>
        </thead>
        <tbody>
        <tr class="active-row">
            <td>Arya Wijaya</td>
            <td>Saint dan Informatika</td>
            <td>Informatika</td>
            <td>A</td>
        </tr>
        <tr class="active-row ">
            <td>Muhamad Yasir Noval</td>
            <td>Saint dan Informatika</td>
            <td>Informatika</td>
            <td>A</td>
        </tr>
        <tr class="active-row">
            <td>Muhamad Yusron Noval</td>
            <td>Saint dan Informatika</td>
            <td>Informatika</td>
            <td>A</td>
        </tr>
        <tr class="active-row">
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
