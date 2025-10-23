USE 9_dars;

ALTER TABLE orders
ADD order_status VARCHAR(20) DEFAULT 'pending';

CREATE INDEX idx_status
ON orders (product_id, order_status);