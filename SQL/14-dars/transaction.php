<?php

$db_name = 'bank';
$db_user = 'root';
$db_password = 'root';
$server_name = 'localhost';

$conn = new mysqli($server_name, $db_user, $db_password, $db_name);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);

try {
    $conn->begin_transaction();

    $result1 = $conn->query("UPDATE accounts SET balance = balance - 100 WHERE id = 1");
    if ($conn->affected_rows !== 1) {
        throw new Exception("not enough funds (id=1)");
    }

    $result2 = $conn->query("UPDATE accounts SET balance = balance + 100 WHERE id = 8");
    if ($conn->affected_rows !== 1) {
        throw new Exception("not enough funds (id=2)");
    }

    $conn->commit();
    echo "Transaction completed successfully.";
} catch (Exception $e) {
    $conn->rollback();
    echo "Transaction failed: " . $e->getMessage();
}
?>
