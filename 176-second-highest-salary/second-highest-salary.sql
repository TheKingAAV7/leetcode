
-- select e.salary as SecondHighestSalary from Employee e 
-- where max(e.salary) < (select max(salary) from employee)

select max(x.salary) as SecondHighestSalary from (
select * from Employee o 
where  o.salary < (select max(salary) from employee)

) as x


-- select e.salary as SecondHighestSalary from employee e
-- where e.id = (select id from employee order by salary desc limit 1 offset 1)