USE my_sql_db;

CREATE UNIQUE INDEX idx_unique_email
ON users (email);

-- DROP INDEX idx_unique_email
-- ON users;