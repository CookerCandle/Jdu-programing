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
        <form  method="post" class="d-flex flex-column gap-3 w-25 mx-auto">
            <input type="text" class="form-control" placeholder="username" name="user_name" >
            <input type="password" class="form-control" placeholder="password" name="password">
            <button type="submit" class="btn btn-primary">Submit</button>
        </form>
    </div>
    <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $user_name = $_POST['user_name'];
            $password = $_POST['password'];

            if (($user_name == "admin" || $user_name == "user") && $password == 12345) {
                setcookie("user_name", $user_name, time() + 300);
                setcookie("password", $password, time() + 300);

                if ($user_name == "admin") {
                    header("Location: /9-dars/1-vazifa/admin.php");
                    exit();
                } elseif ($user_name == "user") {
                    header("Location: /9-dars/1-vazifa/user.php");
                    exit();
                }
            }
        }

        if (isset($_COOKIE["user_name"])) {
            if ($_COOKIE["user_name"] == "admin") {
                header("Location: /9-dars/1-vazifa/admin.php");
                exit();
            } elseif ($_COOKIE["user_name"] == "user") {
                header("Location: /9-dars/1-vazifa/user.php");
                exit();
            }
        }

    ?>
</body>
</html>
</html>