<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php 
    $viloyatlar = ['Toshkent', 'Samarqand', 'Buxoro', 'Farg\'ona', 'Andijon', 'Namangan', 'Qashqadaryo', 'Surxondaryo', 'Jizzax', 'Sirdaryo', 'Xorazm', 'Navoiy', 'Qoraqalpog\'iston'];
    ?>
    <h1>foydalanuvchi qo'shish</h1>
    <form action="3-vazifa.php" method="post">
        <label for="ism">Ism:</label>
        <input type="text" id="ism" name="ism" required>
        <br>
        <label for="familiya">Familiya:</label>
        <input type="text" id="familiya" name="familiya" required>
        <br>
        <label for="telefon_raqam">Telefon Raqam:</label>
        <input type="number" id="telefon_raqam" name="telefon_raqam">
        <br>
        <label for="viloyat">Viloyat:</label>
        <select id="viloyat" name="viloyat" required>
            <?php foreach ($viloyatlar as $viloyat): ?>
                <option value="<?php echo $viloyat; ?>"><?php echo $viloyat; ?></option>
            <?php endforeach; ?>
        </select>
        <br>
        <input type="submit" value="Qo'shish">
    </form>
    <?php 

    $db_name = 'my_php_db';
    $db_user = 'root';
    $db_password = 'root';
    $server_name = 'localhost';

    if ($_SERVER["REQUEST_METHOD"] === "POST") {
        $connection = new mysqli($server_name, $db_user, $db_password, $db_name);

        $query = "INSERT INTO foydalanuvchilar (ism, familiya, telefon_raqam, viloyat) 
            VALUES ('$_POST[ism]', '$_POST[familiya]', '$_POST[telefon_raqam]', '$_POST[viloyat]');";
        $result = $connection->query($query);

        if ($connection->connect_error) {
            die("connection error". $connection->connect_error);
        };
    }

    ?>
</body>
</html>