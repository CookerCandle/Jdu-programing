<?php
function ildiz($son)  {
    if ($son < 0) {
        throw new Exception("Xatolik: Ildiz osti manfiy son bo'lishi mumkin emas!");
    }
    return sqrt($son);
}

try {
    echo ildiz(9);
} catch (Exception $e) {
    echo $e->getMessage();
}
?>