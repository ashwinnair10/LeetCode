# Write your MySQL query statement below
select p.project_id,avg(e.experience_years) as average_years from Project as p join Employee as e on e.employee_id=p.employee_id group by p.project_id