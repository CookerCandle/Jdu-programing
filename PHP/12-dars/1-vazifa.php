<?php
    session_start();
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $email = $_POST['email'] ?? '';
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $_SESSION['errors']['email'] = "Email noto'g'ri, to'g'ri formatda kiriting.";
        } else {
            unset($_SESSION['errors']['email']);
            $_SESSION['success'] = "Email manzili to'g'ri";
        }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>email tekshirish</title>
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
        <label for="email">Email manzilingizni kiriting:</label><br>
        <input type="email" id="email" name="email" class="form-control mx-2" value="<?= $_POST['email'] ?? '' ?>" required>
        <div class="text-danger"><?= $_SESSION['errors']['email'] ?? '' ?></div><br>
        <button type="submit" class="btn btn-primary">Tekshirish</button>
    </form>
</body>
</html>