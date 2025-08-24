<?php
    $user_login = "admin";
    $user_password = "12345";

    if ($_SERVER["REQUEST_METHOD"] === "POST") {
        $login = $_POST["login"];
        $password = $_POST["password"];

        if ($login === $user_login && $password === $user_password) {
            echo "Kirish muvaffaqiyatli!";
        } else {
            echo "Login yoki parol noto'g'ri.";
        }
    }
?>