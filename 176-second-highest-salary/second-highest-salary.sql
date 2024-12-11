# Write your MySQL query statement below

select max(salary) as SecondHighestSalary
from (
select * from Employee e
where e.salary < (select max(f.salary) from Employee f )
) as st;
