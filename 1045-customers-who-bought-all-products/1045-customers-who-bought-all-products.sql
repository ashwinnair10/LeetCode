# Write your MySQL query statement below
select a.customer_id from 
(select customer_id,count(product_key) as p from Customer group by customer_id) as a join
(select count(product_key) as c from Product) as b on a.p=b.c