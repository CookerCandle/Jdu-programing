USE ums;

CREATE TABLE talabalar (
    id INT PRIMARY KEY AUTO_INCREMENT,
    ismi VARCHAR(50) NOT NULL,
    familiyasi VARCHAR(50) NOT NULL,
    viloyati VARCHAR(50) NOT NULL,
    bahosi INT CHECK (bahosi BETWEEN 0 AND 5)
);

INSERT INTO talabalar (ismi, familiyasi, viloyati, bahosi) VALUES
('Ali', 'Valiyev', 'Toshkent', 5),
('Oyna', 'Murodova', 'Samarqand', 4),
('Jasurbek', 'Qodirov', 'Buxoro', 3),
('Nilufar', 'Karimova', 'Jizzax', 2),
('Ahmad', 'Islomov', 'Andijon', 0),
('Madina', 'Saidova', 'Namangan', 4),
('Alisher', 'Toshpulatov', 'Qashqadaryo', 5),
('Gulnora', 'Raximova', 'Surxondaryo', 4),
('Davron', 'Xolmatov', 'Jizzax', 0),
('Zarina', 'Abdullaeva', 'Sirdaryo', 5),
('Kamol', 'Yusupov', 'Xorazm', 5),
('Lola', 'Nurmuhamedova', 'Navoiy', 4);