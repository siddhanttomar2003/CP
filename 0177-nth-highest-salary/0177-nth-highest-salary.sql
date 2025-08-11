CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  Set N = N - 1;
  RETURN (
      SELECT  DISTINCT SALARY FROM Employee order by salary desc limit 1 offset N 
  );
END