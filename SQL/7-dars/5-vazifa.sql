USE ums;

SELECT group_id, COUNT(*) AS student_count
FROM students
GROUP BY group_id;
