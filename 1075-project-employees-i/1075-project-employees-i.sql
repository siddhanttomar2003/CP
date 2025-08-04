# Write your MySQL query statement below
select p1.project_id as project_id , round(avg(p2.experience_years),2) as average_years
from Project p1
left join 
Employee p2
on p1.employee_id = p2.employee_id
group by p1.project_id;