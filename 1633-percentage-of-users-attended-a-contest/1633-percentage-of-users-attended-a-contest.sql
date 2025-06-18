SELECT 
  r.contest_id,
  ROUND((COUNT(DISTINCT r.user_id) * 100.0) / (SELECT COUNT(*) from Users), 2) AS percentage
FROM Register r
JOIN Users u ON u.user_id = r.user_id
GROUP BY r.contest_id
order by percentage desc,r.contest_id asc;
