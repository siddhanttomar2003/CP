# Write your MySQL query statement below
select round(sum(d.row_num = 1 and d.order_date = d.customer_pref_delivery_date) / count(distinct d.customer_id)*100,2) as immediate_percentage from(
select  customer_id,order_date,customer_pref_delivery_date,row_number() over(partition by customer_id order by order_date) as row_num
from Delivery) as d

