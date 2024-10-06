# Write your MySQL query statement below

select x.name, x.bonus 
from(
select e.name, b.bonus from bonus b
right join employee e on
b.empId=e.empId 
) x
where x.bonus is null or x.bonus<1000