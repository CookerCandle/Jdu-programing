USE universitet;

SELECT yonalishi, COUNT(first_name) AS talaba_soni FROM talabalar
GROUP BY yonalishi;
