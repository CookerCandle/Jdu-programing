CREATE DATABASE 9_dars;
USE 9_dars;

CREATE TABLE students(
    student_id INT PRIMARY KEY,
    first_name VARCHAR(25),
    last_name VARCHAR(25)
);

CREATE TABLE courses(
    course_id INT PRIMARY KEY,
    course_name VARCHAR(50),
    instructor VARCHAR(50)
);

CREATE TABLE enrollments (
    enrollment_id INT PRIMARY KEY,
    student_id INT,
    course_id INT,
    FOREIGN KEY (student_id) REFERENCES students(student_id),
    FOREIGN KEY (course_id) REFERENCES courses(course_id)
);
-- --------------------------------

INSERT INTO students(student_id, first_name, last_name)
VALUES
(1, 'alex', 'hirsch'),
(2, 'john', 'doe'),
(3, 'jane', 'smith'),
(4, 'emily', 'jones'),
(5, 'michael', 'brown'),
(6, 'sarah', 'davis'),
(7, 'david', 'wilson'),
(8, 'linda', 'taylor'),
(9, 'james', 'anderson'),
(10, 'patricia', 'thomas');

INSERT INTO courses(course_id, course_name, instructor)
VALUES
(1, 'Database Systems', 'Dr. Smith'),
(2, 'Web Development', 'Prof. Johnson'),
(3, 'Data Science', 'Dr. Lee'),
(4, 'Machine Learning', 'Prof. Brown'),
(5, 'Computer Networks', 'Dr. Davis');

INSERT INTO enrollments(enrollment_id, student_id, course_id)
VALUES
(1, 1, 1),
(2, 1, 2),
(3, 2, 1),
(4, 2, 3),
(5, 3, 2),
(6, 3, 4),
(7, 4, 5),
(8, 5, 1),
(9, 6, 3),
(10, 7, 4),
(11, 8, 2),
(12, 9, 5),
(13, 10, 1);

-- -------------------

SELECT students.first_name, courses.course_name, courses.instructor
FROM students
JOIN enrollments ON enrollments.student_id = students.student_id
JOIN courses ON courses.course_id = enrollments.course_id