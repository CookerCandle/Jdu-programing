<?php 
    session_start();
    $title = isset($_GET['id']) ? "Xodim malumotlari" : "Xodim qo'shish";
    include 'blocks/header.php';
    include 'blocks/db_connection.php';

    if (isset($_GET['id'])) {
        $id = $_GET['id'];

        $query = "SELECT * FROM xodimlar_14_15 WHERE id = $id";
        $result = $connection->query($query);        
        $xodim = $result->fetch_assoc();

        if ($xodim) {
            $_SESSION['user_id'] = $xodim['user_id'];
            $_SESSION['name'] = $xodim['ism'];
            $_SESSION['familiya'] = $xodim['familiya'];
        } else {
            unset($_SESSION['user_id'], $_SESSION['name'], $_SESSION['familiya'], $_SESSION['errors']);
            header('Location: xodim.php');
            exit;
        }
    }
?>
    <div class="container">
        <form action="forms/add_xodim.php" method="POST" enctype="multipart/form-data">
            <div class="form-group">
                <label for="name">Xodim ID</label>
                <input type="text" class="form-control" placeholder="Xodim ID" id="user_id" name="user_id" value="<?= $_SESSION['user_id'] ?? ''?>" required>
                <div class="text-danger"><?= $_SESSION['errors']['user_id'] ?? '' ?></div>
            </div>
            <div class="form-group">
                <label for="name">Xodim ismi</label>
                <input type="text" class="form-control" placeholder="Xodim ismi" id="name" name="name" value="<?= $_SESSION['name'] ?? ''?>" required>
                <div class="text-danger"><?= $_SESSION['errors']['name'] ?? '' ?></div>
            </div>
            <div class="form-group">
                <label for="count">Xodim familiyasi</label>
                <input type="text" class="form-control" placeholder="Xodim familiyasi" id="familiya" name="familiya" value="<?= $_SESSION['familiya'] ?? ''?>" required>
                <div class="text-danger"><?= $_SESSION['errors']['familiya'] ?? '' ?></div>
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