<?php
    session_start();

    $id = $_POST['id'] ?? '';
    $name = $_POST['name'] ?? '';
    $lastname = $_POST['lastname'] ?? '';
    
    $_SESSION['errors'] = [];
    $_SESSION['name'] = $name;
    $_SESSION['lastname'] = $lastname;
    $_SESSION['id'] = $id;

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        if (strlen($name) < 3) {
            $_SESSION['errors']['name'] = "Ism kamida 3 ta belgidan iborat bo'lishi kerak.";
        }

        if (!ctype_alpha($name)) {
            $_SESSION['errors']['name'] = "Ism faqat harflardan iborat bo'lishi kerak.";
        }
        if (strlen($lastname) < 3) {
            $_SESSION['errors']['lastname'] = "Familiya kamida 3 ta belgidan iborat bo'lishi kerak.";
        }

        if (!ctype_alpha($lastname)) {
            $_SESSION['errors']['lastname'] = "Familiya faqat harflardan iborat bo'lishi kerak.";
        }

        if (!is_numeric($id) || $id < 1) {
            $_SESSION['errors']['id'] = "ID 1 dan katta bo'lgan son bo'lishi kerak.";
        }

        if (empty($_SESSION['errors'])) {
            unset($_SESSION['name'], $_SESSION['lastname'], $_SESSION['id']);
            $_SESSION['success'] = "Ism, familiya va ID to'g'ri kiritildi.";
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
    <form method="post" class="form mt-5">
        <div class="form-group">
            <label for="id">IDingizni kiriting:</label><br>
            <input type="number" id="id" name="id" class="form-control mx-2" value="<?= $_SESSION['id'] ?? '' ?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['id'] ?? '' ?></div><br>
        </div>
            <div class="form-group">
            <label for="name">Ismingizni kiriting:</label><br>
            <input type="text" id="name" name="name" class="form-control mx-2" value="<?= $_SESSION['name'] ?? '' ?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['name'] ?? '' ?></div><br>
        </div>
        </div>
            <div class="form-group">
            <label for="lastname">Familiyangizni kiriting:</label><br>
            <input type="text" id="lastname" name="lastname" class="form-control mx-2" value="<?= $_SESSION['lastname'] ?? '' ?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['lastname'] ?? '' ?></div><br>
        </div>
        <button type="submit" class="btn btn-primary">Tekshirish</button>
    </form>
        <?php if (isset($_SESSION['success'])): ?>
        <div class="alert alert-success mt-5" role="alert">
            <?= $_SESSION['success'] ?>
            <p class="mt-2">ID: <?= $id ?></p>
            <p class="mt-2">Ism: <?= $name ?></p>
            <p class="mt-2">Familiya: <?= $lastname ?></p>
        </div>
        <?php unset($_SESSION['success']); ?>
    <?php endif; ?> 
</body>
</html>