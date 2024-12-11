# Write your MySQL query statement below
-- select e.name as Employee from 
-- employee e
-- where
-- e.salary > (select m.salary from employee m where m.id=e.managerId )

SELECT e2.name as Employee
FROM employee e1
INNER JOIN employee e2 ON e1.id = e2.managerID
WHERE
e1.salary < e2.salary