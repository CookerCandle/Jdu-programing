<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>asaxiy</title>
</head>
<body>
    <h1>Foydalanuvchilar!</h1>
    <?php 
    $db_name = 'my_php_db';
    $db_user = 'root';
    $db_password = 'root';
    $server_name = 'localhost';

    $connection = new mysqli($server_name, $db_user, $db_password, $db_name);

    $query = "SELECT * FROM foydalanuvchilar;";
    $result = $connection->query($query);

    if ($connection->connect_error) {
        die("connection error". $connection->connect_error);
    };

    if ($result) {
        $users = $result->fetch_all(MYSQLI_ASSOC);
    };
    ?>

    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Ism</th>
                <th>Familiya</th>
                <th>Telefon Raqam</th>
                <th>Viloyat</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($users as $key => $user): ?>
                <tr>
                    <td><?php echo $user["id"]; ?></td>
                    <td><?php echo $user["ism"]; ?></td>
                    <td><?php echo $user["familiya"]; ?></td>
                    <td><?php echo $user["telefon_raqam"]; ?></td>
                    <td><?php echo $user["viloyat"]; ?></td>
                </tr>
            <?php endforeach; ?>
    </table>
</body>
</html>