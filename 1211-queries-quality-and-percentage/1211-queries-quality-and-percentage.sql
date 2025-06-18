# Write your MySQL query statement below
select query_name,ROUND(SUM((rating*1.0) / (position*1.0)) / COUNT(*),2) as quality, ROUND((SUM(rating < 3) / COUNT(*)) * 100,2) as poor_query_percentage
from Queries
where query_name is not null
group by query_name;