USE 9_dars;

CREATE INDEX idx_order
ON orders (customer_id, order_date);
