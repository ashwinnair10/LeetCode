select r.contest_id,round(r.c*100/count(distinct u.user_id),2) as percentage from (select contest_id,count(user_id) as c from Register group by contest_id) as r join Users as u group by r.contest_id order by percentage desc,r.contest_id asc