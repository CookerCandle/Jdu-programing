<?php
    $a = 10;
    $b = 18;
    $c = 7;

    if ($a > $b && $a > $c) {
        echo "A is the largest number.";
    } elseif ($b > $a && $b > $c) {
        echo "B is the largest number.";
    } else {
        echo "C is the largest number.";
    }
?>