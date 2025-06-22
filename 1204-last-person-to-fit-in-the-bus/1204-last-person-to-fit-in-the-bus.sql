# Write your MySQL query statement below
with temp as (
    select * , SUM(weight) over (order by turn) as cum_sum from Queue
)

select person_name from temp where cum_sum in(
Select MAX(cum_sum) from temp where cum_sum <= 1000)
