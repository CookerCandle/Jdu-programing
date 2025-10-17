USE joins_db;

CREATE TABLE authors (
    author_id INT PRIMARY KEY,
    first_name VARCHAR(25),
    last_name VARCHAR(25)
);

CREATE TABLE books (
    book_id INT PRIMARY KEY,
    author_id INT,
    title VARCHAR(255),
    FOREIGN KEY (author_id) REFERENCES authors(author_id) 
);

INSERT INTO authors (author_id, first_name, last_name) VALUES
(1, 'Orhan', 'Pamuk'),
(2, 'Elif', 'Shafak'),
(3, 'Ahmet', 'Hamdi Tanpinar'),
(4, 'Jamol', 'Gofurov');

INSERT INTO books (book_id, author_id, title) VALUES
(1, 1, 'My Name is Red'),
(2, 1, 'Snow'),
(3, 2, 'The Bastard of Istanbul'),
(4, 3, 'A Mind at Peace');

-- ----------------------------

SELECT authors.first_name, authors.last_name, books.title
FROM authors
LEFT JOIN books ON books.author_id = authors.author_id;