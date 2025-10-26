USE bank;

CREATE USER 'user1'@'localhost' IDENTIFIED BY '12345';
CREATE USER 'user2'@'localhost' IDENTIFIED BY '12345';
CREATE USER 'user3'@'localhost' IDENTIFIED BY '12345';

GRANT SELECT ON bank.accounts TO 'user1'@'localhost', 'user2'@'localhost', 'user3'@'localhost';

GRANT INSERT ON bank.accounts TO 'user1'@'localhost';
GRANT UPDATE ON bank.accounts TO 'user2'@'localhost';
GRANT DELETE ON bank.accounts TO 'user3'@'localhost';

