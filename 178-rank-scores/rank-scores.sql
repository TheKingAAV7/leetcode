# Write your MySQL query statement below
select s.score ,
dense_rank() over w as 'rank'
from scores s 
window w as (
    order by score desc
)

