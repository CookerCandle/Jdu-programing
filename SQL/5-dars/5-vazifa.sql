USE amazon;

DELETE FROM kategoriyalar WHERE nomi = 'Electronics';
DELETE FROM kategoriyalar WHERE nomi = 'Furniture';

UPDATE kategoriyalar SET nomi = 'Clothes' WHERE nomi = 'Clothing';
UPDATE kategoriyalar SET nomi = 'Games' WHERE nomi = 'Toys';
UPDATE kategoriyalar SET nomi = 'Office Supplies' WHERE nomi = 'Stationery';