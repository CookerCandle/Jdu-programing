USE joins_db;

CREATE TABLE departaments (
    departament_id INT PRIMARY KEY,
    departament_name VARCHAR(255)
);

CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    first_name VARCHAR(25),
    last_name VARCHAR(25),
    departament_id INT,
    FOREIGN KEY (departament_id) REFERENCES departaments (departament_id)
);

INSERT INTO departaments (departament_id, departament_name) VALUES
(1, 'Human Resources'),
(2, 'Finance'),
(3, 'IT'),
(4, 'Marketing');

INSERT INTO employees (employee_id, first_name, last_name, departament_id) VALUES
(1, 'John', 'Doe', 1),
(2, 'Jane', 'Smith', 2),
(3, 'Mike', 'Johnson', 3),
(4, 'Emily', 'Davis', 4),
(5, 'David', 'Wilson', NULL);  
-- -----------------------------------

SELECT employees.first_name, employees.last_name, departaments.departament_name
FROM departaments
RIGHT JOIN employees ON employees.employee_id = departaments.departament_id;
