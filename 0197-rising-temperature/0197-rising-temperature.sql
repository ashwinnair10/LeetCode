# Write your MySQL query statement below
select w2.id as Id from Weather as w1 join Weather as w2 where datediff(w2.recordDate,w1.recordDate)=1 and w1.temperature<w2.temperature