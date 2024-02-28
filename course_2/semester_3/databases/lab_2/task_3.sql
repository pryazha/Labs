SELECT lastname AS "Фамилия", employment_day AS "Дата устройства"
FROM table_прядеин 
WHERE DATEDIFF(CURRENT_DATE(), employment_day) > 4 * 365;
