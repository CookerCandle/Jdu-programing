CREATE DATABASE joins_db;

USE joins_db;

CREATE TABLE students (
    student_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50)
);

CREATE TABLE enrollments (
    enrolment_id INT PRIMARY KEY,
    student_id INT,
    course_name VARCHAR(100),
    FOREIGN KEY (student_id) REFERENCES students(student_id)
);

INSERT INTO students (student_id, first_name, last_name) VALUES
(1, 'Ali', 'Valiyev'),
(2, 'Sara', 'Huseynova'),
(3, 'Kamran', 'Mammadov');

INSERT INTO enrollments (enrolment_id, student_id, course_name) VALUES
(1, 1, 'Mathematics'),
(2, 1, 'Physics'),
(3, 2, 'Chemistry');

-- ----------------------------

SELECT students.first_name, students.last_name, enrollments.course_name 
FROM students
INNER JOIN enrollments ON enrollments.student_id = students.student_id;