<?php 
    session_start();
    $title = "Talabalar Davomat tizimi"; 
    include 'blocks/header.php';
    include 'blocks/db_connection.php';

    if (!isset($_GET['user']) || ($_GET['user'] != 'talaba' && $_GET['user'] != 'xodim')) {
        header("Location: /davomat-tizimi");
        exit();
    }
    $user = $_GET['user'];
    $table = $user == 'talaba' ? 'universitet_talabalar' : 'universitet_xodimlar';
    if (isset($_GET['id'])) {
        $id = $_GET['id'];

        $query = "SELECT * FROM $table WHERE id = $id";
        $result = $connection->query($query);        
        $xodim = $result->fetch_assoc();

        if ($xodim) {
            $_SESSION['user_id'] = $xodim['user_id'];
            $_SESSION['name'] = $xodim['ism'];
            $_SESSION['last_name'] = $xodim['familiya'];
        } else {
            unset($_SESSION['user_id'], $_SESSION['name'], $_SESSION['last_name'], $_SESSION['errors']);
            header('Location: /davomat-tizimi/create.php'.'?user='.$_GET['user']);
            exit;
        }
    }
    
?>
    <?php include 'blocks/sidebar.php'; ?>

        <!-- Page Content -->
        <div id="page-content-wrapper">
            <?php include 'blocks/navbar.php'; ?>

            <div class="container-fluid px-4">
                <div class="row">
                    <div class="row text-center">
                        <h3 class="fs-3 mb-3 "><?= $user == 'talaba' ? "Talaba ma'lumotlarini kiriting" : "Xodim ma'lumotlarini kiriting" ?></h3>
                    </div>
                    <div class="col">
                        <form action="/davomat-tizimi/forms/add_user.php" method="post" class="d-flex flex-column align-items-center">
                            <div class="mb-3 w-75 text-center fs-5 text-uppercase">
                              <label for="student_id" class="form-label"><?= $user == 'talaba' ? "Talaba" : "Xodim" ?> ID:</label>
                              <input type="text" class="form-control" id="student_id" name="user_id" autocomplete="off" value="<?= $_SESSION['user_id'] ?? '' ?>">
                              <div class="text-danger"><?= $_SESSION['errors']['user_id'] ?? '' ?></div>
                            </div>
                            <div class="mb-3 w-75 text-center fs-5 text-uppercase">
                                <label for="student_id" class="form-label"><?= $user == 'talaba' ? "Talaba" : "Xodim" ?> Ismi</label>
                                <input type="text" class="form-control" id="student_id" name="name" autocomplete="off" value="<?= $_SESSION['name'] ?? '' ?>">
                                <div class="text-danger"><?= $_SESSION['errors']['name'] ?? '' ?></div>
                              </div>
                              <div class="mb-3 w-75 text-center fs-5 text-uppercase">
                                <label for="student_id" class="form-label"><?= $user == 'talaba' ? "Talaba" : "Xodim" ?> Familiyasi:</label>
                                <input type="text" class="form-control" id="student_id" name="last_name" autocomplete="off" value="<?= $_SESSION['last_name'] ?? '' ?>">
                                <div class="text-danger"><?= $_SESSION['errors']['last_name'] ?? '' ?></div>
                              </div>
                              <?php if (isset($_GET['id'])): ?>
                                <input type="hidden" name="edit" value="<?= $_GET['id'] ?? '' ?>">
                              <?php endif; ?>
                              <?php if (isset($_GET['user'])): ?>
                                <input type="hidden" name="user" value="<?= $_GET['user'] ?? '' ?>">
                              <?php endif; ?>
                          <div class="d-flex ">
                            <button type="submit" class="btn btn-primary">Jo'natish</button>
                          </div>
                          </form>
                    </div>
                </div>

            </div>
        </div>
    </div>
    <!-- /#page-content-wrapper -->
    </div>

    <?= include 'blocks/footer.php'; ?>