USE barcelona;

CREATE TRIGGER before_update_player BEFORE UPDATE
ON futbolchilar FOR EACH ROW SET NEW.yillik = (12 * NEW.oylik);

SHOW TRIGGERS;