<?php
session_start();

require_once '../../../config/config.php';

if (isset($_GET['id'])) {
    try {
        $query = "SELECT p.*, r.status 
                  FROM pembayaran p
                  JOIN reservasi r ON p.id_reservasi = r.id_reservasi
                  WHERE p.id_pembayaran = :id";
        $stmt = $conn->prepare($query);
        $stmt->execute([':id' => $_GET['id']]);
        $pembayaran = $stmt->fetch(PDO::FETCH_ASSOC);

        if ($pembayaran) {
            header('Content-Type: application/json');
            echo json_encode($pembayaran);
        } else {
            http_response_code(404);
            echo json_encode(['error' => 'Data tidak ditemukan']);
        }
    } catch (PDOException $e) {
        http_response_code(500);
        echo json_encode(['error' => $e->getMessage()]);
    }
}
