<?php
    session_start();
    $name = $_POST['name'] ?? '';
    $age = $_POST['age'] ?? '';

    $_SESSION['errors'] = []; 
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    


        if (strlen($name) < 3) {
            $_SESSION['errors']['name'] = "Ism kamida 3 ta belgidan iborat bo'lishi kerak.";
        }

        if (!ctype_alpha($name)) {
            $_SESSION['errors']['name'] = "Ism faqat harflardan iborat bo'lishi kerak.";
        }

        if (!is_numeric($age) || $age < 1 || $age > 120) {
            $_SESSION['errors']['age'] = "Yosh 1 dan 120 gacha bo'lgan son bo'lishi kerak.";
        }

        if (empty($_SESSION['errors'])) {
            $_SESSION['success'] = "Ism va yosh to'g'ri kiritildi.";
        }
    }

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ism va yosh tekshirish</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
</head>
<body class="bg-light container">
    <?php if (isset($_SESSION['success'])): ?>
        <div class="alert alert-success mt-5" role="alert">
            <?= $_SESSION['success'] ?>
        </div>
        <?php unset($_SESSION['success']); ?>
    <?php endif; ?>    
    <form method="post" class="form mt-5">
        <div class="form-group">
            <label for="name">Ismingizni kiriting:</label><br>
            <input type="text" id="name" name="name" class="form-control mx-2" value="<?= $_POST['name'] ?? '' ?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['name'] ?? '' ?></div><br>
        </div>
            <div class="form-group">
            <label for="age">Yoshingizni kiriting:</label><br>
            <input type="number" id="age" name="age" class="form-control mx-2" value="<?= $_POST['age'] ?? '' ?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['age'] ?? '' ?></div><br>
        </div>
        <button type="submit" class="btn btn-primary">Tekshirish</button>
    </form>
</body>
</html>