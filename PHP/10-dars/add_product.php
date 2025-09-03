<?php 
    session_start();
    $title = "Mahsulot qo'shish";
    include 'blocks/header.php';
?>
    <h1 class="mb-4">Mahsulot qo'shish</h1>
    <?php if (isset($_SESSION['success'])): ?>
        <div class="alert alert-success" role="alert">
            <?= $_SESSION['success'] ?>
        </div>
        <?php unset($_SESSION['success']); ?>
    <?php endif; ?>
    <form action="forms/save_product.php" method="POST">
        <div class="form-group">
            <label for="name">Mahsulot nomi</label>
            <input type="text" class="form-control" placeholder="Mahsulot nomi" id="name" name="name" value="<?= $_SESSION['name'] ?? ''?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['name'] ?? '' ?></div>
        </div>
        <div class="form-group">
            <label for="count">Mahsulot soni</label>
            <input type="number" class="form-control" placeholder="Mahsulot soni" id="count" name="count" value="<?= $_SESSION['count'] ?? ''?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['count'] ?? '' ?></div>
        </div>
        <div class="form-group">
            <label for="price">Mahsulot narxi</label>
            <input type="text" class="form-control" placeholder="Mahsulot narxi" id="price" name="price" value="<?= $_SESSION['price'] ?? ''?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['price'] ?? '' ?></div>
        </div>
        <button type="submit" class="btn btn-primary">Saqlash</button>
    </form>

<?php 
    include 'blocks/footer.php';
?>