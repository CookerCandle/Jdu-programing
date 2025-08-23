<?php
    $talaba = 55;

    if ($talaba < 0 && $talaba > 100) {
        echo "Talaba bahosi noto'g'ri.";
    } elseif ($talaba >= 86) {
        echo "talaba 5 oldi";
    } elseif ($talaba >= 71 && $talaba <= 85) {
        echo "talaba 4 oldi";
    } elseif ($talaba >= 56 && $talaba <= 70) {
        echo "talaba 3 oldi";
    } else {
        echo "talaba yeqildi";
    }
?>