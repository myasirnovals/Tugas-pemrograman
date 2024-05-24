<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Tugas Kelompok Web Page</title>
    <!-- Style CSS -->
    <style>
        body#body {
            background-color: #dbd2d2;
        }
    </style>

    <!-- link Bootstrap CSS -->
    <link rel="stylesheet" href="../css/bootstrap.css">
</head>
<body class="container-fluid" id="body">
<div class="container bg-white mt-5 mb-4 rounded shadow">
    <!-- header -->
    <?php
    include "header.php"
    ?>
    <div class="row">
        <div class="col-4">
            <!-- sidebar -->
            <?php
            include "sidebar.php";
            ?>
        </div>
        <div class="col-1"></div>
        <div class="col-7">
            <!-- body of main article -->
            <?php
            include "bodyPage.php";
            ?>
        </div>
    </div>
    <!-- footer of web page -->
    <?php
    include "footer.php";
    ?>
</div>
<!-- link Bootstrap JavaScript -->
<script src="../js/bootstrap.js"></script>
</body>
</html>