# Write your MySQL query statement below
select distinct a.num as ConsecutiveNums from
Logs as a join Logs as b join Logs as c on a.id=b.id-1 and b.id=c.id-1 where a.num=b.num and b.num=c.num