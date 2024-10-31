select p.user_id as user_id,if(q.num=0,0,q.num/(q.num+p.den)) as confirmation_rate from 
(select a.user_id as user_id,count(b.action) as den from Signups as a left join (select * from Confirmations where action="timeout") as b on a.user_id=b.user_id group by a.user_id) 
as p join
(select a.user_id as user_id,count(b.action) as num from Signups as a left join (select * from Confirmations where action="confirmed")as b on a.user_id=b.user_id group by a.user_id) 
as q on p.user_id=q.user_id 