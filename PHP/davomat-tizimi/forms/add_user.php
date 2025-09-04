<?php
    session_start();

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $user_id = $_POST['user_id'];
        $name = $_POST['name'];
        $last_name = $_POST['last_name'];
        $user = $_POST['user'];
        $table = $user == 'talaba' ? 'universitet_talabalar' : 'universitet_xodimlar';

    }

        $errors = [];
        if (strlen($name) < 3) 
            $errors['name'] = "Xodim ismi kamida 3 ta belgidan iborat bo'lishi kerak";
        if (strlen($last_name) < 3)
            $errors['last_name'] = "Xodim familiyasi kamida 3 ta belgidan iborat bo'lishi kerak";
        if (!is_numeric($user_id) || $user_id < 0)
            $errors['user_id'] = "Xodim ID musbat son bo'lishi kerak";


        if (empty($errors)) {
            unset($_SESSION['user_id'], $_SESSION['name'], $_SESSION['last_name'], $_SESSION['errors']);


            include '../blocks/db_connection.php';
            if (isset($_POST['edit'])){
                $id = $_POST['edit'];
                $query = "UPDATE $table SET user_id = '$user_id', ism = '$name', familiya = '$last_name' WHERE id = $id";
                header('Location: /davomat-tizimi' . ($user == 'talaba' ? '' : '/xodimlar.php'));
            } else {
                $query = "INSERT INTO $table (user_id, ism, familiya) VALUES ('$user_id', '$name', '$last_name')";
                header('Location: /davomat-tizimi' . ($user == 'talaba' ? '' : '/xodimlar.php'));
            }
            $result = $connection->query($query);
            exit();
        } else {
            $_SESSION['errors'] = $errors;
            $_SESSION['user_id'] = $user_id;
            $_SESSION['name'] = $name;
            $_SESSION['last_name'] = $last_name;
            header('Location: /davomat-tizimi/create.php'.'?user='.$_POST['user'].(isset($_POST['edit']) ? '&id='.$_POST['edit'] : ''));
            exit;
        }
        echo "Xatolik yuz berdi";
?>
