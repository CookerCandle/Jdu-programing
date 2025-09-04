<?php 
    include '../blocks/db_connection.php';

    if ($_SERVER['REQUEST_METHOD'] === 'GET') {
        $id = $_GET['id'];

        $query = "DELETE FROM xodimlar_14_15 WHERE id = $id";
        $result = $connection->query($query);

        header("Location: ../");
        exit();
    }
?>