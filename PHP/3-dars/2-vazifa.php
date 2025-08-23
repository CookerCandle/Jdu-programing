<!DOCTYPE html>
<html lang="en">
<head>
    <title>Document</title>
</head>
<body>
    <?php
        for ($i = 1; $i <= 100; $i++) {
            if ($i % 10 == 0) {
                echo "<nobr><b>$i</b> </nobr><br>";
            } else {
                echo "<nobr>$i </nobr>";
            }
        }
        ?>

</body>
</html>