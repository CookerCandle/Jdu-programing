<?php
    session_start();

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $name = $_POST['name'];
        $count = $_POST['count'];
        $price = $_POST['price'];

        $errors = [];
        if (strlen($name) < 3) 
            $errors['name'] = "Mahsulot nomini to'g'ri kiritishingiz kerak";
        if ($count <= 0)
            $errors['count'] = "Mahsulot sonini to'g'ri kiritishingiz kerak";
        if (!is_numeric($price) || $price <= 0) 
            $errors['price'] = "Mahsulot narxini to'g'ri kiritishingiz kerak";

        if (empty($errors)) {
            unset($_SESSION['name'], $_SESSION['count'], $_SESSION['price'], $_SESSION['errors']);
            

            include '../blocks/db_connection.php';
            if (isset($_POST['edit'])){
                $id = $_POST['edit'];
                $query = "UPDATE mahsulotlar_10_dars SET nomi = '$name', soni = $count, narxi = $price WHERE id = $id";
                header('Location: ../change_product.php');
            } else {
                $_SESSION['success'] = "Mahsulot muvaffaqiyatli qo'shildi";
                $query = "INSERT INTO mahsulotlar_10_dars (nomi, soni, narxi) VALUES ('$name', $count, $price)";
                header('Location: ../add_product.php');
            }
            $result = $connection->query($query);
            
            exit;
        } else {
            $_SESSION['errors'] = $errors;
            $_SESSION['name'] = $name;
            $_SESSION['count'] = $count;
            $_SESSION['price'] = $price;
            header('Location: ../add_product.php');
            exit;
        }
    }
    # UPDATE `my_php_db`.`mahsulotlar_10_dars` SET `nomi` = 'telefon', `soni` = '8', `narxi` = '9600' WHERE (`id` = '2');
?>
