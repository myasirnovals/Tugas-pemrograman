<?php

require_once __DIR__ . "/UploadData.php";

date_default_timezone_set('Asia/Jakarta');

function AddGame()
{
    $gameId = uniqid();
    $name = htmlspecialchars($_POST["gameName"]);
    $image = UploadsImage();
    $created_at = date('l, d / M / Y  H:i:s');
    $updated_at = date('l, d / M / Y  H:i:s');

    if (!$image) {
        return false;
    }

    $file_name = "../database/data_game" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        $extra = array(
            "gameId" => $gameId,
            "gameName" => $name,
            "image" => $image,
            "created_at" => $created_at,
            "updated_at" => $updated_at
        );

        $array_data[] = $extra;
        return json_encode($array_data);
    } else {
        $dataError = array();
        $dataError[] = array(
            "gameId" => $gameId,
            "gameName" => $name,
            "image" => $image,
            "created_at" => $created_at,
            "updated_at" => $updated_at
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}

function AddGameProduct()
{
    $product_id = uniqid();
    $product_name = htmlspecialchars($_POST["name"]);
    $product_price = htmlspecialchars($_POST["price"]);
    $product_bonus = htmlspecialchars($_POST["bonus"]);
    $product_code = htmlspecialchars($_POST["gameCode"]);
    $image = UploadsImageProduct();
    $created_at = date('l, d / M / Y  H:i:s');
    $updated_at = date('l, d / M / Y  H:i:s');

    if (!$image) {
        return false;
    }

    $file_name = "../database/data_product" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        $extra = array(
            "productId" => $product_id,
            "productName" => $product_name,
            "productPrice" => $product_price,
            "productBonus" => $product_bonus,
            "gameCode" => $product_code,
            "image" => $image,
            "created_at" => $created_at,
            "updated_at" => $updated_at
        );

        $array_data[] = $extra;
        return json_encode($array_data);
    } else {
        $dataError = array();
        $dataError[] = array(
            "productId" => $product_id,
            "productName" => $product_name,
            "productPrice" => $product_price,
            "productBonus" => $product_bonus,
            "gameCode" => $product_code,
            "image" => $image,
            "created_at" => $created_at,
            "updated_at" => $updated_at
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}

function AddDataUser()
{
    // data exist
    $memberId = uniqid();
    $address = "-";
    $birthdate = "-";
    $image = "-";
    $bio = "-";
    $created_at = date('l, d / M / Y  H:i:s');
    $updated_at = date('l, d / M / Y  H:i:s');

    // filter data
    $name = filter_input(INPUT_POST, 'name', FILTER_SANITIZE_STRING);
    $username = filter_input(INPUT_POST, 'username', FILTER_SANITIZE_STRING);
    $members = filter_input(INPUT_POST, 'members', FILTER_SANITIZE_STRING);
    $phone = filter_input(INPUT_POST, 'phone', FILTER_SANITIZE_NUMBER_INT);


    // verify email
    $email = filter_input(INPUT_POST, 'email', FILTER_VALIDATE_EMAIL);

    // encryption password
    $password = password_hash($_POST['password'], PASSWORD_BCRYPT);

    $file_name = "../database/data_member" . ".json";

    if (file_exists("$file_name")) {
        $current_data = file_get_contents("$file_name");
        $array_data = json_decode($current_data, true);

        $extra = array(
            "memberId" => $memberId,
            "name" => $name,
            "address" => $address,
            "bio" => $bio,
            "birthdate" => $birthdate,
            "username" => $username,
            "members" => $members,
            "phone" => $phone,
            "email" => $email,
            "password" => $password,
            "image" => $image,
            "created_at" => $created_at,
            "updated_at" => $updated_at
        );

        $array_data[] = $extra;
        return json_encode($array_data);
    } else {
        $dataError = array();
        $dataError[] = array(
            "memberId" => $memberId,
            "name" => $name,
            "address" => $address,
            "bio" => $bio,
            "birthdate" => $birthdate,
            "username" => $username,
            "members" => $members,
            "phone" => $phone,
            "email" => $email,
            "password" => $password,
            "image" => $image,
            "created_at" => $created_at,
            "updated_at" => $updated_at
        );

        echo "File not exist <br>";
        return json_encode($dataError);
    }
}

function AddOrder($data_email, $id_product)
{
    // data exist
    $order_id = uniqid();
    $created_at = date('l, d / M / Y  H:i:s');
    $updated_at = date('l, d / M / Y  H:i:s');

    // get data from database
    $file_order = "../database/data_order" . ".json";
    $file_member = "../database/data_member" . ".json";
    $file_product = "../database/data_product" . ".json";

    // verify all file
    if (
        file_exists("$file_order") &&
        file_exists("$file_member") &&
        file_exists("$file_product")
    ) {
        $data_member = file_get_contents("$file_member");
        $array_member = json_decode($data_member, true);

        foreach ($array_member as $member) {
            if ($member['email'] == $data_email) {
                $data_product = file_get_contents("$file_product");
                $data_product = json_decode($data_product, true);

                foreach ($data_product as $product) {
                    if($product['productId'] == $id_product) {
                        $data_order = file_get_contents("$file_order");
                        $array_order = json_decode($data_order, true);

                        $extra = array(
                            "orderId" => $order_id,
                            "orderMemberId" => $member['memberId'],
                            "orderPersonName" => $member['name'],
                            "orderPersonEmail" => $member['email'],
                            "orderProductName" => $product['productName'],
                            "orderProductPrice" => $product['productPrice'],
                            "orderProductCode" => $product['productId'],
                            "orderProductImage" => $product['image'],
                            "orderStatus" => "not yet paid",
                            "image" => $product['image'],
                            "created_at" => $created_at,
                            "updated_at" => $updated_at
                        );

                        $array_order[] = $extra;
                        return json_encode($array_order);
                    }
                }

                return "Product is not exist<br>";
            }
        }

        return "Member is not exist<br>";
    } else {
        return "File not exist <br>";
    }
}