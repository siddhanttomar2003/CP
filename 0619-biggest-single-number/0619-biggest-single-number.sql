# Write your MySQL query statement below
with temp as (
    select num,count(*) as freq
    from MyNumbers
    group by num
)

select MAX(num) as num from temp where freq = 1;