USE 9_dars;

CREATE INDEX idx_name
ON students (first_name);

SELECT * FROM students
WHERE first_name = 'john';