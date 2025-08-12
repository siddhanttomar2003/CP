WITH temp AS (
    SELECT 
        e1.departmentId,
        e1.name AS emp,
        e1.salary,
        d1.name AS department,
        Dense_RANK() OVER (PARTITION BY d1.name ORDER BY e1.salary DESC) AS ra
    FROM Employee e1
    LEFT JOIN Department d1
        ON e1.departmentId = d1.id

)
SELECT 
    t.department AS Department,
    t.emp AS Employee,
    t.salary AS Salary
FROM temp t
WHERE t.ra <= 3  order by t.salary desc;
