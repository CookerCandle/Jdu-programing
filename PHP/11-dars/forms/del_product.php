<?php 
    include '../blocks/db_connection.php';

    $base_dir = "../images/";

    if ($_SERVER['REQUEST_METHOD'] === 'GET') {
        $id = $_GET['id'];

        $query = "SELECT rasm_url FROM mashinalar WHERE id = $id";
        $result = $connection->query($query);
        $product = $result->fetch_assoc();

        if ($product && $product['rasm_url'] !== 'not_found.jpg') {
            $imagePath = $base_dir . basename($product['rasm_url']);
            if (file_exists($imagePath)) {
                unlink($imagePath);
            }
        }

        $query = "DELETE FROM mashinalar WHERE id = $id";
        $result = $connection->query($query);        

        header("Location: ../change.php");
        exit();
    }
?>