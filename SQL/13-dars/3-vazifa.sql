USE universitet;

SELECT viloyati, COUNT(first_name) AS talaba_soni
FROM talabalar
GROUP BY viloyati
ORDER BY COUNT(first_name) DESC;