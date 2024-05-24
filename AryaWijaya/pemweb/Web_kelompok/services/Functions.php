<?php

require_once __DIR__ . "/GetConnection.php";

$connection = getConnection();

function queryData($queryData)
{
    global $connection;
    $statement = $connection->prepare($queryData);
    $statement->execute();

    $statement->setFetchMode(PDO::FETCH_OBJ);
    $result = $statement->fetchAll();

    foreach ($result as $row) {
        return $row;
    }
}

function addData($data)
{
    global $connection;

    $name = htmlspecialchars($data['name']);
    $nim = htmlspecialchars($data['nim']);
    $address = htmlspecialchars($data['address']);
    $hobby = htmlspecialchars($data['hobby']);

    $query = "INSERT INTO data_formulir (nim, nama, alamat, hobby) VALUES (:nim, :name, :address, :hobby)";
    $result = $connection->prepare($query);

    $data = [
        ':nim' => $nim,
        ':name' => $name,
        ':address' => $address,
        ':hobby' => $hobby,
    ];

    return $result->execute($data);
}