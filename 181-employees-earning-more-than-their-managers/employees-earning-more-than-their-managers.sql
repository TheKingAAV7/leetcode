# Write your MySQL query statement below
select e.name as Employee from 
employee e
where
e.salary > (select m.salary from employee m where m.id=e.managerId )