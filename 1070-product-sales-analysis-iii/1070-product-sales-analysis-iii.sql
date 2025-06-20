# Write your MySQL query statement below
with temp as (
    select product_id,MIN(year) as first_year from 
    Sales group by product_id
)
select  s.product_id,s.year as first_year,s.quantity as quantity, s.price as price
from Sales as s
LEFT JOIN 
temp as t
on t.product_id = s.product_id 
where t.first_year = s.year;


