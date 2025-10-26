CREATE DATABASE bank;

USE bank;

CREATE TABLE accounts(
	id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    balance DEC(10,2)
);