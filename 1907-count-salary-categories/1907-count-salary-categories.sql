SELECT 'Low Salary' AS category, COALESCE(SUM(account_id > 0), 0) AS accounts_count
FROM Accounts
WHERE income BETWEEN 0 AND 19999

UNION ALL

SELECT 'Average Salary' AS category, COALESCE(SUM(account_id > 0), 0) AS accounts_count
FROM Accounts
WHERE income >= 20000 AND income <= 50000

UNION ALL

SELECT 'High Salary' AS category, COALESCE(SUM(account_id > 0), 0) AS accounts_count
FROM Accounts
WHERE income > 50000;
