select e.name as Employee from Employee e
where e.managerId is not null and e.salary > (select salary from Employee where id=e.managerId);