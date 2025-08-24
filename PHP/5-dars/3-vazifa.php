<?php 
    $talabalar = [];

    $talabalar[] = ["id" => 123, "ism" => "Ali", "guruh" => 1];
    $talabalar[] = ["id" => 245, "ism" => "Hasan", "guruh" => 3];
    $talabalar[] = ["id" => 852, "ism" => "Dilshod", "guruh" => 2];
    $talabalar[] = ["id" => 111, "ism" => "Botir", "guruh" => 2];
    $talabalar[] = ["id" => 942, "ism" => "Ahmad", "guruh" => 1];

    function FilterByGroup($talabalar, $guruh) {
        $result = [];
        foreach ($talabalar as $id => $talaba) {
            if ($talaba['guruh'] == $guruh) {
                $result[] = $talaba;
            }
        }
        return $result;
    }

    echo json_encode(FilterByGroup($talabalar, 2));
?>