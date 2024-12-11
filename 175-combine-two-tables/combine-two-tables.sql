# Write your MySQL query statement below
select p.firstName, p.lastName , e.city, e.state
from 
Person p
left join Address e
on p.personId=e.personId