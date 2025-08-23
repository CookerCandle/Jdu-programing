<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php 
        $talaba = ["Ali", "Vali", "Hasan", "Husan"];
        echo "<ol>";
        foreach ($talaba as $ism) {
            echo "<li>$ism</li>";
        }
        echo "</ol>";
    ?>
</body>
</html>