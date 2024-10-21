CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE nth_highest_salary INT;
  DECLARE offset INT;

  -- Return NULL if N is less than 1
  IF N <= 0 THEN
    RETURN NULL;
  END IF;


  SET offset = N - 1;
  

  SELECT DISTINCT salary
  INTO nth_highest_salary
  FROM employee
  ORDER BY salary DESC
  LIMIT offset, 1;
  
  RETURN nth_highest_salary;
END;
