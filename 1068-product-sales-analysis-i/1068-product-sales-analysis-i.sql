# Write your MySQL query statement below
select P.product_name,S.year,S.price from Sales as S
LEFT JOIN 
Product as P 
on S.product_id = P.product_id;