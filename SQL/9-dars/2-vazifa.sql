USE 9_dars;

CREATE TABLE customers(
    customer_id INT PRIMARY KEY,
    first_name VARCHAR(25),
    last_name VARCHAR(25)
);

CREATE TABLE products(
    product_id INT PRIMARY KEY,
    product_name VARCHAR(50),
    price INT
);

CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    product_id INT,
    order_date DATE DEFAULT (CURRENT_DATE()),
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id),
    FOREIGN KEY (product_id) REFERENCES products(product_id)
);
-- --------------------------------

INSERT INTO customers(customer_id, first_name, last_name)
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

INSERT INTO products(product_id, product_name, price)
VALUES
(1, 'APPLE', 300),
(2, 'BANANA', 400),
(3, 'CHERRY', 500),
(4, 'DATE', 600),
(5, 'ELDERBERRY', 700);

INSERT INTO orders(order_id, customer_id, product_id)
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

SELECT products.product_name, customers.first_name, orders.order_date
FROM orders
LEFT JOIN products ON products.product_id = orders.product_id
LEFT JOIN customers ON customers.customer_id = orders.customer_id