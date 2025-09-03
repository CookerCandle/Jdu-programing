<?php 
    include '../blocks/db_connection.php';

    if ($_SERVER['REQUEST_METHOD'] === 'GET') {
        $id = $_GET['id'];

        $query = "DELETE FROM mahsulotlar_10_dars WHERE id = $id";
        $result = $connection->query($query);        

        header("Location: ../change_product.php");
        exit();
    }
?>