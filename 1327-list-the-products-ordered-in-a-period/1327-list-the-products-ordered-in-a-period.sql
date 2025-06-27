# Write your MySQL query statement below
with temp as(
    select p.product_id as product_id,p.product_name as product_name,o.unit as unit,o.order_date as order_date from Products p
    LEFT JOIN 
    Orders o on p.product_id = o.product_id
)
-- select * from temp;
select product_name ,sum(unit) as unit from temp 
where YEAR(order_date) = 2020 and MONTH(order_date) = 2
group by product_id having sum(unit) >= 100;