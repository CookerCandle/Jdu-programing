USE ums;

CREATE TABLE students (
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    ismi VARCHAR(50) NOT NULL,
    familiyasi VARCHAR(50) NOT NULL,
    group_id INT,
    FOREIGN KEY (group_id) REFERENCES `groups`(group_id)
);