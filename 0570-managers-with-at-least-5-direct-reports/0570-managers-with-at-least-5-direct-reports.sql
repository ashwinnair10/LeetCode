# Write your MySQL query statement below
select p.name from Employee as p join Employee as q  where q.managerId=p.id group by p.name having count(q.managerId)>=5