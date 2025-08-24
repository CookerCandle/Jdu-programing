<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php 
        $talabalar = [
            ["id" => 123, "ism" => "Ali", "yosh" => 20],     
        ];

        $talabalar[] = ["id" => 124, "ism" => "Vali", "yosh" => 22];
        $talabalar[] = ["id" => 125, "ism" => "Hasan", "yosh" => 20];
        $talabalar[] = ["id" => 126, "ism" => "Husan", "yosh" => 19];
        $talabalar[] = ["id" => 125, "ism" => "Hasan", "yosh" => 18];
        $talabalar[] = ["id" => 127, "ism" => "Husniddin", "yosh" => 22];

        foreach ($talabalar as $talaba) {
            echo "ID: " . $talaba['id'] . ", Ism: " . $talaba['ism'] . ", Yosh: " . $talaba['yosh'] . "<br>";
        }
    ?>
</body>
</html>