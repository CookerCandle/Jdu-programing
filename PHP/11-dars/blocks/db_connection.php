<?php
    $db_name = 'my_php_db';
    $db_user = 'root';
    $db_password = 'root';
    $server_name = 'localhost';

    $connection = new mysqli($server_name, $db_user, $db_password, $db_name);

    if ($connection->connect_error) {
        die("Connection failed: " . $connection->connect_error);
    }

?>