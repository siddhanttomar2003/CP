# Write your MySQL query statement below
Select p.product_id,IFNULL(ROUND(SUM(u.units*p.price)/SUM(u.units),2),0) as average_price
From Prices as p
LEFT JOIN
UnitsSold as u
ON p.product_id = u.product_id 
AND p.start_date <= u.purchase_date and u.purchase_date <= p.end_date
group by p.product_id;