<?php 
    include '../blocks/db_connection.php';

    if ($_SERVER['REQUEST_METHOD'] === 'GET') {
        $id = $_GET['id'];
        $user = $_GET['user'];
        $table = $user == 'talaba' ? 'universitet_talabalar' : 'universitet_xodimlar';

        $query = "DELETE FROM $table WHERE id = $id";
        $result = $connection->query($query);

        header("Location: /davomat-tizimi". ($user == 'talaba' ? '' : '/xodimlar.php'));
        exit();
    }
?>