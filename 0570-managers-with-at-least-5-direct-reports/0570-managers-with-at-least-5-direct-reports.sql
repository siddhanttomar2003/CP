# Write your MySQL query statement below
SELECT T1.name as name from Employee T1 
JOIN 
Employee T2
on 
T1.id = T2.managerId 
group by T1.id having count(*) >= 5;
