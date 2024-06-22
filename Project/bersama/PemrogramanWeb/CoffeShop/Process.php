<?php
header('Content-Type: application/json');

$cart = json_decode(file_get_contents('php://input'), true);

if (!$cart) {
    echo json_encode(['message' => 'Invalid cart data']);
    exit;
}

// Simpan data pesanan ke dalam database atau lakukan pemrosesan lainnya
// ...

echo json_encode(['message' => 'Order successfully processed']);
?>
