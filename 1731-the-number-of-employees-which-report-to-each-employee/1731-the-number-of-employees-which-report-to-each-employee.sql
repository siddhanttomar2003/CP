# Write your MySQL query statement below
select e1.employee_id,e1.name,count(*) as reports_count,ROUND(AVG(e2.age),0) as average_age
from Employees e1
LEFT JOIN
Employees e2
on e1.employee_id = e2.reports_to where e2.reports_to is NOT NULL
group by e1.employee_id
order by e1.employee_id;
