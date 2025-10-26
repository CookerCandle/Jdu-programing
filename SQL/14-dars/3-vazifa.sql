USE bank;

START TRANSACTION;
UPDATE accounts SET balance = balance - 300 WHERE id = 1;
UPDATE accounts SET balance = balance + 300 WHERE id = 3;
COMMIT;

START TRANSACTION;
UPDATE accounts SET balance = balance - 300 WHERE id = 2;
UPDATE accounts SET balance = balance + 300 WHERE id = 6;
COMMIT;

START TRANSACTION;
UPDATE accounts SET balance = balance - 300 WHERE id = 70;
UPDATE accounts SET balance = balance + 300 WHERE id = 3;
ROLLBACK;

START TRANSACTION;
UPDATE accounts SET balance = balance - 300 WHERE id = 7;
UPDATE accounts SET balance = balance + 300 WHERE id = 1;
COMMIT;

START TRANSACTION;
UPDATE accounts SET balance = balance - 300 WHERE id = 6;
UPDATE accounts SET balance = balance + 300 WHERE id = 45;
ROLLBACK;

START TRANSACTION;
UPDATE accounts SET balance = balance - 300 WHERE id = 9;
UPDATE accounts SET balance = balance + 300 WHERE id = 8;
COMMIT;

