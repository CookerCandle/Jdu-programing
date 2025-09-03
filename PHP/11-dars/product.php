<?php 
    session_start();
    $title = isset($_GET['id']) ? "Mahsulotni tahrirlash" : "Mahsulot qo'shish";
    include 'blocks/header.php';
    include 'blocks/db_connection.php';

    if (isset($_GET['id'])) {
        $id = $_GET['id'];

        $query = "SELECT * FROM mashinalar WHERE id = $id";
        $result = $connection->query($query);        
        $product = $result->fetch_assoc();

        if ($product) {
            $_SESSION['name'] = $product['nomi'];
            $_SESSION['count'] = $product['soni'];
            $_SESSION['price'] = $product['narxi'];
        } else {
            unset($_SESSION['name'], $_SESSION['count'], $_SESSION['price'], $_SESSION['errors']);
            header('Location: product.php');
            exit;
        }
    }
?>
    <div class="container">
        <h1 class="mb-4"><?= $title ?></h1>
        <?php if (isset($_SESSION['success'])): ?>
            <div class="alert alert-success" role="alert">
                <?= $_SESSION['success'] ?>
            </div>
            <?php unset($_SESSION['success']); ?>
        <?php endif; ?>
        <form action="forms/add_product.php" method="POST" enctype="multipart/form-data">
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
            <div class="form-group">
                <label for="image">Mahsulot rasmi</label><br>
                <input type="file" class="" id="image" name="image">
                <div class="text-danger"><?= $_SESSION['errors']['image'] ?? '' ?></div>
            </div>
            <?php if (isset($_GET['id'])): ?>
                <input type="hidden" name="edit" value="<?= $_GET['id'] ?? '' ?>">
            <?php endif; ?>
            <button type="submit" class="btn btn-primary">Saqlash</button>
        </form>
    </div>

<?php 
    include 'blocks/footer.php';
?>