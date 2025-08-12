# Write your MySQL query statement below
select p1.product_name, sum(o1.unit) as unit
from 
Products p1
LEFT JOIN
Orders o1
on p1.product_id = o1.product_id where YEAR(o1.order_date) = '2020' and MONTH(o1.order_date) = '2' group by p1.product_id having sum(o1.unit) >= 100;
