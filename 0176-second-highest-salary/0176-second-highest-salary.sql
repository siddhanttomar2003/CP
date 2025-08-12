# Write your MySQL query statement below
select coalesce((select max(salary) from Employee where salary != (select max(salary) from Employee)), NULL) as SecondHighestSalary;