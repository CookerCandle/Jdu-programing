<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php 
        $fruits = ["olma", "anor", "uzum", "shaftoli", "tarvuz"];
        array_push($fruits, "nok", "anjir");
        
        $fruits[0] = "malina";
        $fruits[1] = "golubika";

        echo "<ol type='1'>";
            foreach ($fruits as $fruit)  echo "<li>$fruit</li>";
        echo "</ol>";

    ?>
</body>
</html>