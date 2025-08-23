<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php 
        $son = 4;
        $tub = true;

        if ($son <= 1) {
            echo "$son tub son emas";
        } else {
            $i = 2;
            while ($i <= sqrt($son)) {
                if ($son % $i == 0) {
                    $tub = false;
                    break;
                }
                $i++;
            }
            if ($tub) {
                echo "<p>$son tub son</p>";
            } else {
                echo "<p>$son tub son emas</p>";
            }
        }
    ?>
</body>
</html>