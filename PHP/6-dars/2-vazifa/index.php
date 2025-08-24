<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="2-vazifa/form.php" method="post">
        <label for="id">ID:</label>
        <input type="number" name="id">

        <label for="name">Ism:</label>
        <input type="text" name="name">

        <label for="lastname">Familiya:</label>
        <input type="text" name="lastname">

        <label for="country">Viloyat:</label>
        <select name="country">
            <?php
                $regions = [
                    "Toshkent", "Samarqand", "Buxoro", 
                    "Andijon", "Fargona", "Namangan", "Qashqadaryo", 
                    "Surxondaryo", "Xiva"
                ];
                foreach ($regions as $region) {
                    echo "<option value='$region'>" . htmlspecialchars($region) . "</option>";
                }
            ?>
        </select>
        <button type="submit">Yuborish</button>

    </form>
</body>
</html>