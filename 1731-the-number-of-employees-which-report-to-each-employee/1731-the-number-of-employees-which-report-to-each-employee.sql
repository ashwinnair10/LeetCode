# Write your MySQL query statement below
select distinct a.employee_id,a.name,count(b.reports_to) as reports_count,round(avg(b.age)) as average_age  from Employees as a 
join Employees as b
on a.employee_id=b.reports_to
group by a.employee_id