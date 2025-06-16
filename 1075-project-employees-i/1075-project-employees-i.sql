# Write your MySQL query statement below
Select p.project_id,IFNULL(ROUND(AVG(e.experience_years),2),0) as average_years
FROM Project p
LEFT JOIN
Employee e
on p.employee_id = e.employee_id
group by p.project_id;