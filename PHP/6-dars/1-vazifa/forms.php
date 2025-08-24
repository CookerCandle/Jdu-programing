<?php 
    $name = $_POST['ism'];
    $lastname = $_POST['familiya'];

    echo "Ism: " . htmlspecialchars($name) . "<br>";
    echo "Familiya: " . htmlspecialchars($lastname) . "<br>";
?>