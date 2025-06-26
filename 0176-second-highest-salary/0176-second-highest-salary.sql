# Write your MySQL query statement below
with temp as (
    select salary , dense_rank() over (order by salary desc)  as ranks from Employee
)
-- select * from temp;
SELECT COALESCE((select  salary  from temp where ranks = 2 limit 1 ),NULL) as SecondHighestSalary;