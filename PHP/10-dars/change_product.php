<?php
    $title = "Mahsulot o'chirish";
    include 'blocks/header.php';

    include 'blocks/db_connection.php';
    $query = "SELECT `id`, `nomi` FROM mahsulotlar_10_dars";
    $result = $connection->query($query);
?>
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
                    <th>Amallar</th>
                </tr>
            </thead>
            <tbody>
                <?php while ($row = $result->fetch_assoc()) : ?>
                    <tr>
                        <td><?= $row['id'] ?></td>
                        <td><?= $row['nomi'] ?></td>
                        <td>
                            <a href="forms/del_product.php?id=<?= $row['id'] ?>" class="btn btn-danger">O'chirish</a>
                            <a href="forms/edit_product.php?id=<?= $row['id'] ?>" class="btn btn-warning">Tahrirlash</a>
                        </td>
                    </tr>
                <?php endwhile; ?>
            </tbody>
        </table>
<?php
    include 'blocks/footer.php';
?>