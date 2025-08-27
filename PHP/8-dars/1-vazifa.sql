CREATE DATABASE asaxiy;

USE asaxiy;

CREATE TABLE foydalanuvchilar (
    id INT AUTO_INCREMENT PRIMARY KEY,
    ism VARCHAR(25) NOT NULL,
    familiya VARCHAR(25) NOT NULL,
    telefon_raqam BIGINT(13),
    viloyat VARCHAR(35)
);