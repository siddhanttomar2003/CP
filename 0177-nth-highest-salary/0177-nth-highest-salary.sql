CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  
  RETURN (
     select salary from (select salary, dense_rank()  over(order by salary desc) as ra   from Employee) as temp where ra = N limit 1
  );
END