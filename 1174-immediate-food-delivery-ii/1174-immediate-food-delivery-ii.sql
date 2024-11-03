
select round(sum(if(order_date=customer_pref_delivery_date,1,0))/count(customer_id)*100,2) as immediate_percentage from Delivery where (customer_id,order_date) in (select customer_id as cid,min(order_date) as firstorderdate from Delivery group by customer_id order by customer_id)
