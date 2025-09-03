<?php
    session_start();

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $name = $_POST['name'];
        $count = $_POST['count'];
        $price = $_POST['price'];

        $uploadDir = "../images/";
        $imagePath = '';
        if (!empty($_FILES["image"]["name"])) {
            $fileName = time() . "_" . basename($_FILES["image"]["name"]);
            $targetFile = $uploadDir . $fileName;

            if (move_uploaded_file($_FILES["image"]["tmp_name"], $targetFile)) {
                $imagePath = $targetFile;
        }
    }
        // $fileName = basename($_FILES["image"]["name"]);
        // $targetFile = $uploadDir . time() . "_" . $fileName;

        $errors = [];
        if (strlen($name) < 3) 
            $errors['name'] = "Mashina nomini to'g'ri kiritishingiz kerak";
        if ($count <= 0)
            $errors['count'] = "Mashina sonini to'g'ri kiritishingiz kerak";
        if (!is_numeric($price) || $price <= 0) 
            $errors['price'] = "Mashina narxini to'g'ri kiritishingiz kerak";

        if (empty($errors)) {
            unset($_SESSION['name'], $_SESSION['count'], $_SESSION['price'], $_SESSION['errors']);
            

            include '../blocks/db_connection.php';
            if (isset($_POST['edit'])){
                $id = $_POST['edit'];
                $_SESSION['success'] = "Mashina muvaffaqiyatli tahrirlandi";
                if ($imagePath) {
                    $query = "UPDATE mashinalar SET nomi = '$name', soni = $count, narxi = $price, rasm_url = '$imagePath' WHERE id = $id";
                } else {
                    $query = "UPDATE mashinalar SET nomi = '$name', soni = $count, narxi = $price WHERE id = $id";
                }
                header('Location: ../change.php');
            } else {
                $_SESSION['success'] = "Mashina muvaffaqiyatli qo'shildi";
                if ($imagePath) {
                    $query = "INSERT INTO mashinalar (nomi, soni, narxi, rasm_url) VALUES ('$name', $count, $price, '$imagePath')";
                } else {
                    $query = "INSERT INTO mashinalar (nomi, soni, narxi) VALUES ('$name', $count, $price)";
                }
                header('Location: ../product.php');
            }
            $result = $connection->query($query);
            
            exit;
        } else {
            $_SESSION['errors'] = $errors;
            $_SESSION['name'] = $name;
            $_SESSION['count'] = $count;
            $_SESSION['price'] = $price;
            header('Location: ../product.php');
            exit;
        }
    }
?>
