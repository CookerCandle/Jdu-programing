<?php
    session_start();
    $title = "Mahsulot boshqaruvi";
    include 'blocks/header.php';

    include 'blocks/db_connection.php';
    $query = "SELECT `id`, `nomi`, `rasm_url` FROM mashinalar";
    $result = $connection->query($query);

    $base_img_path = '../11-dars/images/';
?>
    <div class="container mt-5">
    <?php if (isset($_SESSION['success'])): ?>
        <div class="alert alert-success" role="alert">
            <?= $_SESSION['success'] ?>
        </div>
        <?php unset($_SESSION['success']); ?>
    <?php endif; ?>
        <h1>Mahsulotlar boshqaruvi</h1>
        <?php if (isset($_SESSION['success'])): ?>
        <div class="alert alert-success" role="alert">
            <?= $_SESSION['success'] ?>
        </div>
        <?php unset($_SESSION['success']); ?>
        <?php endif; ?>
        <table class="table">
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Nomi</th>
                    <th>Rasm</th>
                    <th>Amallar</th>
                </tr>
            </thead>
            <tbody>
                <?php while ($row = $result->fetch_assoc()) : ?>
                    <tr>
                        <td><?= $row['id'] ?></td>
                        <td><?= $row['nomi'] ?></td>
                        <td><img src="<?php echo $base_img_path . $row['rasm_url']; ?>" alt="<?php echo $row['nomi']; ?>" width="100" class="img-fluid"></td>
                        <td>
                            <a href="forms/del_product.php?id=<?= $row['id'] ?>" class="btn btn-danger">O'chirish</a>
                            <a href="product.php?id=<?= $row['id'] ?>" class="btn btn-warning">Tahrirlash</a>
                        </td>
                    </tr>
                <?php endwhile; ?>
            </tbody>
        </table>
    </div>
<?php
    include 'blocks/footer.php';
?>