# Write your MySQL query statement below
select name from Customer C where C.referee_id != 2 OR C.referee_id is NULL;