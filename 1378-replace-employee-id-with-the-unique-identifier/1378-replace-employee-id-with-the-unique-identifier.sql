# Write your MySQL query statement below
select unique_id,name from Employees as e1 
LEFT JOIN
EmployeeUNI as e2 on e1.id = e2.id;