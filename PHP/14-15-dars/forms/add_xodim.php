<?php
    session_start();

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $user_id = $_POST['user_id'];
        $name = $_POST['name'];
        $familiya = $_POST['familiya'];

    }

        $errors = [];
        if (strlen($name) < 3) 
            $errors['name'] = "Xodim ismi kamida 3 ta belgidan iborat bo'lishi kerak";
        if (strlen($familiya) < 3)
            $errors['familiya'] = "Xodim familiyasi kamida 3 ta belgidan iborat bo'lishi kerak";
        if (!is_numeric($user_id) || $user_id <= 0)
            $errors['id'] = "Xodim ID musbat son bo'lishi kerak";


        if (empty($errors)) {
            unset($_SESSION['user_id'], $_SESSION['name'], $_SESSION['familiya'], $_SESSION['errors']);


            include '../blocks/db_connection.php';
            if (isset($_POST['edit'])){
                $id = $_POST['edit'];
                $_SESSION['success'] = "Xodim malumotlari muvaffaqiyatli o'zgartirildi";
                $query = "UPDATE xodimlar_14_15 SET user_id = '$user_id', ism = '$name', familiya = '$familiya' WHERE id = $id";
                header('Location: ../');
            } else {
                $_SESSION['success'] = "Xodim muvaffaqiyatli qo'shildi";
                $query = "INSERT INTO xodimlar_14_15 (user_id, ism, familiya) VALUES ('$user_id', '$name', '$familiya')";
                }
                header('Location: ../');
            $result = $connection->query($query);
            exit;
        } else {
            $_SESSION['errors'] = $errors;
            $_SESSION['name'] = $name;
            $_SESSION['count'] = $count;
            $_SESSION['price'] = $price;
            header('Location: ../xodim.php');
            exit;
        }
?>
