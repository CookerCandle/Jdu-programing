<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php 
        $num1 = 4;
        $num2 = 10;
        $a = 1;
        
        while ($a <= $num2) {
            echo "<p>$num1 * $a = " . ($num1 * $a) . "</p>";
            $a++;
        }
    ?>
</body>
</html>