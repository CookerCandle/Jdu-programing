<?php 
    $id = $_POST['id'];
    $name = $_POST['name'];
    $lastname = $_POST['lastname'];
    $country = $_POST['country'];

    echo "ID: " . htmlspecialchars($id) . "<br>";
    echo "Ism: " . htmlspecialchars($name) . "<br>";
    echo "Familiya: " . htmlspecialchars($lastname) . "<br>";
    echo "Viloyat: " . htmlspecialchars($country) . "<br>";
?>