<?php
    $title = 'Mahsulotlar jadvali';
    include 'blocks/header.php';

    include 'blocks/db_connection.php';
    $query = "SELECT * FROM mahsulotlar_10_dars";
    $result = $connection->query($query);
?>
    <h1 class="mb-4">Mahsulotlar jadvali</h1>
    <table class="table">
        <thead>
            <tr>
                <th scope="col">ID</th>
                <th scope="col">Nomi</th>
                <th scope="col">Soni</th>
                <th scope="col">Narxi</th>
            </tr>
        </thead>
        <tbody>
            <?php while ($row = $result->fetch_assoc()): ?>
            <tr>
                <th scope="row"><?= $row['id'] ?></th>
                <td><?= $row['nomi'] ?></td>
                <td><?= $row['soni'] ?></td>
                <td><?= $row['narxi'] ?></td>
            </tr>
            <?php endwhile; ?>
        </tbody>
    </table>
<?php
    include 'blocks/footer.php';
?>
