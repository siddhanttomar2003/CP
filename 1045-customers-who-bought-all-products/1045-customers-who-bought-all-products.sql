# Write your MySQL query statement below

select customer_id from 
(select customer_id , count(distinct product_key) as freq from Customer 
group by customer_id) as c where c.freq = (select count(*) from Product);
