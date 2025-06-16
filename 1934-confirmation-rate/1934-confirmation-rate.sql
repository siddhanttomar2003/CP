SELECT 
  S1.user_id,
  IFNULL(
  ROUND(
    SUM(C1.action = 'confirmed') / 
    COUNT(*),
    2
  ),0) AS confirmation_rate
FROM Signups AS S1
LEFT JOIN Confirmations AS C1
  ON S1.user_id = C1.user_id
GROUP BY S1.user_id;
