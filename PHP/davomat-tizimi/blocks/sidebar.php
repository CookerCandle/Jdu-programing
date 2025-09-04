    <?php $active_page = basename($_SERVER['PHP_SELF']); ?>
    <div class="d-flex" id="wrapper">
        <!-- Sidebar -->
        <div class="bg-white" id="sidebar-wrapper">
            <div class="sidebar-heading text-center py-4 primary-text fs-4 fw-bold text-uppercase border-bottom"><i
                    class="fas fa-university me-2"></i>UNIVERSITET</div>
            <div class="list-group list-group-flush my-3">
                <a href="/davomat-tizimi" class="list-group-item list-group-item-action bg-transparent second-text <?= $active_page == 'index.php' ? 'active' : '' ?>"><i
                        class="fas fa-university me-2"></i>Talabalar</a>
                <a href="/davomat-tizimi/xodimlar.php" class="list-group-item list-group-item-action bg-transparent second-text fw-bold <?= $active_page == 'xodimlar.php' ? 'active' : '' ?>"><i
                        class="fas fa-university me-2"></i>Xodimlar</a>
                <a href="#" class="list-group-item list-group-item-action bg-transparent second-text fw-bold"><i
                        class="fas fa-university me-2"></i>Guruhlar</a>
                <a href="#" class="list-group-item list-group-item-action bg-transparent second-text fw-bold"><i
                        class="fas fa-book me-2"></i>Fanlar</a>
                <a href="#" class="list-group-item list-group-item-action bg-transparent text-danger fw-bold"><i
                        class="fas fa-power-off me-2"></i>Tizimdan chiqish</a>
            </div>
        </div>