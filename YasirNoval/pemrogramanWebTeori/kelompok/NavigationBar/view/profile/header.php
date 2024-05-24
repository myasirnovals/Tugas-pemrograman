<?php

$path = "../../database/dataMahasiswa.json";
$jsonString = file_get_contents($path);
$jsonData = json_decode($jsonString, true);

?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Navigation Bar</title>
    <link rel="stylesheet" href="../../css/bootstrap.css">
    <style>
        .dropdown-link {
            position: relative;
            display: inline-block;
        }

        .dropdown-content {
            display: none;
            position: absolute;
            background-color: gray;
            border-radius: 10px;
            min-width: 150px;
            box-shadow: 0 8px 16px 0 rgba(0, 0, 0, 0.2);
            z-index: 1;
        }

        .dropdown-content a {
            color: white;
            padding: 12px 16px;
            text-decoration: none;
            display: block;
        }

        .dropdown-content a:hover {
            background-color: whitesmoke;
            color: black;
        }

        .dropdown-content a:active {
            background-color: rgba(245, 245, 245, 0.78);
            color: black;
        }

        .dropdown-link:hover .dropdown-content {
            display: block;
        }
    </style>
</head>
<body>
<div class="container-fluid">
    <div class="container mt-5">
        <nav class="navbar navbar-expand-lg bg-body-tertiary rounded-3">
            <div class="container-fluid">
                <a class="navbar-brand" href="../index.php">Home</a>
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav"
                        aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarNav">
                    <ul class="navbar-nav">
                        <li class="nav-item">
                            <a class="nav-link" href="../index.php">Home</a>
                        </li>
                        <li class="nav-item">
                            <div class="dropdown-link">
                                <button class="nav-link" type="button">Tugas</button>
                                <div class="dropdown-content">
                                    <a href="../tugas/form.php">Form</a>
                                    <a href="../tugas/css.php">CSS</a>
                                    <a href="../tugas/html.php">HTML</a>
                                    <a href="../tugas/php.php">PHP</a>
                                </div>
                            </div>
                        </li>
                        <li class="nav-item">
                            <div class="dropdown-link">
                                <button class="nav-link" type="button">Profile</button>
                                <div class="dropdown-content">
                                    <?php if (!empty($jsonData)) { ?>
                                        <?php foreach ($jsonData as $data) { ?>
                                            <a href="profile.php?nim=<?= $data['nim']; ?>">
                                                <?= $data["nama"]; ?>
                                            </a>
                                        <?php } ?>
                                    <?php } else { ?>
                                        <a href="#">Tidak ada data</a>
                                    <?php } ?>
                                </div>
                            </div>
                        </li>
                        <li class="nav-item">
                            <div class="dropdown-link">
                                <button class="nav-link" type="button">About</button>
                                <div class="dropdown-content">
                                    <a href="../about/MataKuliah.php">Mata Kuliah</a>
                                </div>
                            </div>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>
    </div>
