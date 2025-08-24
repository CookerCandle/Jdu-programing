<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php 
        $yangiliklar = [
            ["sarlavha" => "Uzbekiston", "batafsil" => "Uzbekiston haqida yangiliklar"],     
        ];

        $yangiliklar[] = ["sarlavha" => "USA", "batafsil" => "USA haqida yangiliklar"];
        $yangiliklar[] = ["sarlavha" => "India", "batafsil" => "India haqida yangiliklar"];
        $yangiliklar[] = ["sarlavha" => "Japan", "batafsil" => "Japan haqida yangiliklar"];


        foreach ($yangiliklar as $yangilik) {
            echo  "<h1>{$yangilik['sarlavha']}</h1><p>" . $yangilik['batafsil'] . "</p>";
        }
    ?>
</body>
</html>