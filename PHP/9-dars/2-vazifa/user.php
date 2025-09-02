<?php 
    session_start(); 
    if (!isset($_SESSION["user_name"])) {
        header("Location: /9-dars/2-vazifa/index.php");
        exit();
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css">
</head>
<body>
    <div class="container mt-5">
        <h1>User Information</h1>
        <?php
            echo "<p><strong>Username:</strong> " . $_SESSION["user_name"] . "</p>";
            echo "<p><strong>Password:</strong> " . $_SESSION["password"] . "</p>";
        ?>
        <form method="post">
            <button type="submit" class="btn btn-danger" name="logout">Logout</button>
        </form>
        <?php
            if (isset($_POST["logout"])) {
                session_destroy();
                header("Location: /9-dars/2-vazifa/");
                exit();
            }
        ?>
    </div>
</body>
</html>