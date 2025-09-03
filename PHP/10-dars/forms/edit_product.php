<?php 
    session_start();
        $title = "Mahsulot qo'shish";
    include '../blocks/header.php';
    include '../blocks/db_connection.php';

    if ($_SERVER['REQUEST_METHOD'] === 'GET') {
        $id = $_GET['id'];

        $query = "SELECT * FROM mahsulotlar_10_dars WHERE id = $id";
        $result = $connection->query($query);        
        $product = $result->fetch_assoc();

    }
?>
    <h1 class="mb-4">Tahrirlash</h1>
    <h5>ID: <?= $product['id'] ?></h5>
    <?php if (isset($_SESSION['success'])): ?>
        <div class="alert alert-success" role="alert">
            <?= $_SESSION['success'] ?>
        </div>
        <?php unset($_SESSION['success']); ?>
    <?php endif; ?>
    <form action="save_product.php" method="POST">
        <div class="form-group">
            <label for="name">Mahsulot nomi</label>
            <input type="text" class="form-control" placeholder="Mahsulot nomi" id="name" name="name" value="<?= $product['nomi'] ?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['name'] ?? '' ?></div>
        </div>
        <div class="form-group">
            <label for="count">Mahsulot soni</label>
            <input type="number" class="form-control" placeholder="Mahsulot soni" id="count" name="count" value="<?= $product['soni'] ?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['count'] ?? '' ?></div>
        </div>
        <div class="form-group">
            <label for="price">Mahsulot narxi</label>
            <input type="text" class="form-control" placeholder="Mahsulot narxi" id="price" name="price" value="<?= $product['narxi'] ?>" required>
            <div class="text-danger"><?= $_SESSION['errors']['price'] ?? '' ?></div>
        </div>
        <input type="hidden" name="edit" value="<?= $product['id'] ?>">
        <button type="submit" class="btn btn-primary">Saqlash</button>
    </form>

<?php 
    include '../blocks/footer.php';
?>