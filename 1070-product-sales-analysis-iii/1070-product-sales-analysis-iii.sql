select a.product_id,a.year as first_year,a.quantity,a.price from Sales as a join
(select product_id,min(year) as first_year from Sales group by product_id) as b on
a.product_id=b.product_id and a.year=b.first_year