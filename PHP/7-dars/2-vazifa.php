<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php
    $db_name = 'my_php_db';
    $db_user = 'root';
    $db_password = 'root';
    $server_name = 'localhost';

    $connection = new mysqli($server_name, $db_user, $db_password, $db_name);

    $query = "SELECT * FROM telefonlar;";
    $stmt = $connection->query($query);

    if ($connection->connect_error) {
        die("connection error". $connection->connect_error);
    };

    if ($stmt) {
        $gadgets = $stmt->fetch_all(MYSQLI_ASSOC);
    };
?>
    <table style="border: solid 2px;">
        <thead>
            <tr>
                <th>ID</th>
                <th>Nomi</th>
                <th>Narxi</th>
                <th>Soni</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($gadgets as $key => $gadget): ?>
                <tr>
                    <td><?php echo $gadget["id"]; ?></td>
                    <td><?php echo $gadget["nomi"]; ?></td>
                    <td><?php echo $gadget["narxi"]; ?></td>
                    <td><?php echo $gadget["soni"]; ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</body>
</html>
