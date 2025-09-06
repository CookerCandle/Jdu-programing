USE amazon;

CREATE TABLE mahsulotlar (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nomi VARCHAR(100) NOT NULL,
    narxi DECIMAL(10, 2) NOT NULL,
    kategoriya VARCHAR(25)
);