DELETE p
FROM Person p
JOIN (
    SELECT id,
           DENSE_RANK() OVER (PARTITION BY email ORDER BY id) AS ranks
    FROM Person
) t
ON p.id = t.id
WHERE t.ranks != 1;
