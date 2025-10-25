CREATE DATABASE barcelona;

USE barcelona;

CREATE TABLE futbolchilar(
    id INT PRIMARY KEY AUTO_INCREMENT,
    ismi VARCHAR(50),
    oylik DECIMAL(10, 2),
    yillik DECIMAL(10, 2)
);