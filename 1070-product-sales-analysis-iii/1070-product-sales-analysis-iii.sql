WITH temp AS (
    SELECT product_id, MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
)

SELECT 
    s.product_id,
    t.first_year,
    s.quantity,
    s.price
FROM Sales s
JOIN temp t ON s.product_id = t.product_id
WHERE s.year = t.first_year;
