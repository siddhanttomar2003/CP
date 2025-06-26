# Write your MySQL query statement below
with temp as (
    select *,dense_rank() OVER (partition by departmentId order by salary desc) as ranks from Employee 
)
select d.name as Department , t.name as Employee, t.salary as Salary  from temp as t
LEFT JOIN Department as d
on t.departmentId = d.id
where  t.ranks  in (1,2,3)
order by t.salary desc;


