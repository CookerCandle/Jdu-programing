<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin</title>
</head>
<body>
    <h1>admin</h1>
    <form method="post">
        <input type="submit" value="Clear Cookies" name="clear_cookies">
    </form>
    <?php
    print_r($_COOKIE);
    if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['clear_cookies'])) {
        setcookie("user_name", "", time() - 3600);
        setcookie("password", "", time() - 3600);

        unset($_COOKIE['user_name']);
        unset($_COOKIE['password']);

        header("Location: /9-dars/1-vazifa/");
        exit();
    }
    ?> 
</body>
</html>
