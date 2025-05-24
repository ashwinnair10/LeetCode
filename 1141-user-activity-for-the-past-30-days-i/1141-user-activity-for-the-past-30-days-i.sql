# Write your MySQL query statement below
select  activity_date as day,count(distinct user_id) as active_users from Activity group by day having datediff("2019-07-27",day)<=29