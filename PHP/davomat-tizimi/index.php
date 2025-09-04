<?php 
    $title = "Talabalar Davomat tizimi"; 
    include 'blocks/header.php';
    include 'blocks/db_connection.php';

    $sql = "SELECT * FROM universitet_talabalar";
    $result = $connection->query($sql);
?>
    <?php include 'blocks/sidebar.php'; ?>
        <!-- Page Content -->
        <div id="page-content-wrapper">
            <?php include 'blocks/navbar.php'; ?>

            <div class="container-fluid px-4">
                <div class="row">
                    <div class="row">
                            <div class="col-10">
                                <h3 class="fs-3 mb-3">Talabalar Ro'yxati </h3>
                            </div>
                            <div class="col-2">
                                <a href="davomat-tizimi/create.php?user=talaba" class="btn btn-success">Talaba qo'shish</a>
                            </div>
                    </div>
                    <div class="col">
                        <table class="table bg-white rounded shadow-sm  table-hover">
                            <thead>
                                <tr>
                                    <th scope="col" width="50">#</th>
                                    <th scope="col">Talaba ID</th>
                                    <th scope="col">Talaba Ismi</th>
                                    <th scope="col">Talaba Familiyasi</th>
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
                                            <a href="/davomat-tizimi/create.php?user=talaba&id=<?= $row['id'] ?>" class="btn btn-warning">O'zgartirish</a>
                                            <a href="/davomat-tizimi/forms/del_user.php?user=talaba&id=<?= $row['id'] ?>" class="btn btn-danger">O'chirish</a>
                                        </td>
                                    </tr>
                                <?php endwhile; ?>
                            </tbody>
                        </table>
                    </div>
                </div>

            </div>
        </div>
    </div>
    <!-- /#page-content-wrapper -->
    </div>

<?= include 'blocks/footer.php'; ?>