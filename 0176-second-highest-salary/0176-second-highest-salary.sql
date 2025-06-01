# Write your MySQL query statement below
SELECT COALESCE((select distinct salary  from Employee order by salary DESC LIMIT 1 OFFSET 1),NULL) as "SecondHighestSalary";