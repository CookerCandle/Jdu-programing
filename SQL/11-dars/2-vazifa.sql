USE joins_db;

CREATE VIEW employee_view AS
SELECT employee_id, first_name, last_name, departament_id
FROM employees
WHERE departament_id IS NOT NULL;