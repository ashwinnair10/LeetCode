with il as (select player_id,min(event_date) as idate from Activity group by player_id),
cl as (select a.player_id,b.idate from Activity as a join il as b on a.player_id=b.player_id where datediff(a.event_date,b.idate)=1)
select round(count(distinct a.player_id)/count(distinct b.player_id),2) as fraction from cl as a cross join Activity as b