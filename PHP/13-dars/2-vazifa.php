<?php
function kopaytirish($son1, $son2)  {
    if (!is_numeric($son1) || !is_numeric($son2)) {
        throw new Exception("Xatolik: Ikkala argument ham son bo'lishi kerak!");
    }
    return $son1 * $son2;
}

try {
    echo kopaytirish(8, 4);
} catch (Exception $e) {
    echo $e->getMessage();
}
?>