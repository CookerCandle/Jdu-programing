<?php session_start(); ?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css">
</head>
<body>
    <div class="container mt-5">
        <h1>Registration</h1>
        <form  method="post" class="d-flex flex-column gap-3 w-25 mx-auto">
            <input type="text" class="form-control" placeholder="username" name="user_name" >
            <input type="password" class="form-control" placeholder="password" name="password">
            <button type="submit" class="btn btn-primary">Submit</button>
        </form>
    </div>
    <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $user_name = $_POST['user_name'];
            $password = md5($_POST['password']);

            $db_name = 'my_php_db';
            $db_user = 'root';
            $db_password = 'root';
            $server_name = 'localhost';

            $connection = new mysqli($server_name, $db_user, $db_password, $db_name);

            if ($connection->connect_error) {
                die("Connection failed: " . $connection->connect_error);
            }

            $query = "INSERT INTO user_9_dars (`user_name`, `password`) VALUES ('$user_name', '$password')";
            $result = $connection->query($query);

            $_SESSION["user_name"] = $user_name;
            $_SESSION["password"] = $password;

            header("Location: /9-dars/2-vazifa/user.php");
            exit();
        }

        if (isset($_SESSION["user_name"])) {
            header("Location: /9-dars/2-vazifa/user.php");
            exit();
        }
    ?>
</body>
</html>
