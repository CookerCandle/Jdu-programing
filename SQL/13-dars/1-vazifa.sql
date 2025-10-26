CREATE DATABASE universitet;

USE universitet;

CREATE TABLE talabalar(
id INT PRIMARY KEY AUTO_INCREMENT,
first_name VARCHAR(50),
last_name VARCHAR(50),
viloyati VARCHAR(50),
yonalishi VARCHAR(25)
);

INSERT INTO talabalar(first_name, last_name, viloyati, yonalishi)
VALUES
("jahongir", "qodiraliyev", "toshkent", "IT"),
("jahongir", "qodiraliyev", "toshkent", "IT"),
("aziz", "bekzod", "samarqand", "IT"),
("dilshod", "karimov", "buxoro", "IT"),
("sardor", "olimov", "andijon", "IT"),
("shoxrux", "abdurahmonov", "qashqadaryo", "IT"),
("muhammad", "ismatov", "fargona", "tilshunoslik"),
("bekzod", "toshpulatov", "namangan", "tilshunoslik"),
("javohir", "abdukarimov", "xorazm", "tilshunoslik"),
("sardor", "rahmonov", "surxondaryo", "tilshunoslik"),
("abdulloh", "mamatkulov", "jizzax", "tilshunoslik"),
("aziz", "olimov", "andijon", "kiberxavfsizlik"),
("olim", "toshpulatov", "namangan", "kiberxavfsizlik"),
("jasur", "abdukarimov", "xorazm", "kiberxavfsizlik"),
("nurmuhammad", "rahmonov", "surxondaryo", "kiberxavfsizlik"),
("abdulaziz", "mamatkulov", "jizzax", "kiberxavfsizlik"),
("shoxrux", "qodiraliyev", "toshkent", "dasturlash"),
("aziz", "bekzod", "samarqand", "dasturlash"),
("doston", "karimov", "buxoro", "dasturlash"),
("dilshod", "karimov", "buxoro", "dasturlash"),
("sardor", "olimov", "andijon", "dasturlash"),
("shoxrux", "abdurahmonov", "qashqadaryo", "dasturlash");