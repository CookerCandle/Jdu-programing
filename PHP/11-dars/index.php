<?php 
    $title = 'mashinalar jadvali';
    include 'blocks/header.php';
    include 'blocks/db_connection.php';

    $sql = "SELECT * FROM mashinalar";
    $result = $connection->query($sql);

    $base_img_path = '11-dars/images/';
?>
    <table class="table container mt-5">
        <thead>
            <tr>
                <th>ID</th>
                <th>Nomi</th>
                <th>Soni</th>
                <th>Narxi</th>
                <th>Rasmi</th>
            </tr>
        </thead>
        <tbody>
            <?php while ($row = $result->fetch_assoc()): ?>
                <tr>
                    <td><?php echo $row['id']; ?></td>
                    <td><?php echo $row['nomi']; ?></td>
                    <td><?php echo $row['soni']; ?></td>
                    <td><?php echo $row['narxi']; ?></td>
                    <td><img src="<?php echo $base_img_path . $row['rasm_url']; ?>" alt="<?php echo $row['nomi']; ?>" width="100" class="img-fluid"></td>
                </tr>
            <?php endwhile; ?>
        </tbody>
    </table>
<?php
    include 'blocks/footer.php';
?>