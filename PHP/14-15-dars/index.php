<?php
    session_start(); 
    $title = 'xodimlar jadvali';
    include 'blocks/header.php';
    include 'blocks/db_connection.php';

    $sql = "SELECT * FROM xodimlar_14_15";
    $result = $connection->query($sql);

?>
    <?php if (isset($_SESSION['success'])): ?>
        <div class="alert alert-success container mt-5" role="alert">
            <?= $_SESSION['success'] ?>
        </div>
        <?php unset($_SESSION['success']); ?>
    <?php endif; ?>
    <table class="table container mt-5">
        <thead>
            <tr>
                <th>#</th>
                <th>Xodim_ID</th>
                <th>Xodim ismi</th>
                <th>Xodim familiyasi</th>
                <th>Boshqarish</th>

            </tr>
        </thead>
        <tbody>
            <?php while ($row = $result->fetch_assoc()): ?>
                <tr>
                    <td><?php echo $row['id']; ?></td>
                    <td><?php echo $row['user_id']; ?></td>
                    <td><?php echo $row['ism']; ?></td>
                    <td><?php echo $row['familiya']; ?></td>
                    <td>
                        <a href="/14-15-dars/xodim.php?id=<?= $row['id'] ?>" class="btn btn-warning">O'zgartirish</a><br>
                        <a href="/14-15-dars/forms/del_xodim.php?id=<?= $row['id'] ?>" class="btn btn-danger">O'chirish</a>
                    </td>
                </tr>
            <?php endwhile; ?>
        </tbody>
    </table>
<?php
    include 'blocks/footer.php';
?>