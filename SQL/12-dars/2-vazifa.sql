USE barcelona;

CREATE TRIGGER before_insert_player
BEFORE INSERT ON futbolchilar
FOR EACH ROW SET NEW.yillik = (30 * NEW.oylik);

INSERT INTO futbolchilar(ismi, oylik)
VALUES
("Qo'zivoy", 2500);

SELECT * FROM futbolchilar;