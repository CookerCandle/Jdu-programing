USE amazon;

CREATE TABLE mijozlar (
    id INT PRIMARY KEY AUTO_INCREMENT,
    ism VARCHAR(100) NOT NULL,
    address VARCHAR(255) NOT NULL,
    telefon_raqam VARCHAR(15) NOT NULL
);