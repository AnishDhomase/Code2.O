-- select round(count(*) * 100/(select count(distinct(customer_id)) from Delivery), 2) as immediate_percentage from (select customer_id, min(order_date), customer_pref_delivery_date from Delivery
-- where order_date = customer_pref_delivery_date
-- group by customer_id) T

-- select round(
--     count(if(min(order_date)=customer_pref_delivery_date, 1, 0))*100/count(*)
-- ,2) as immediate_percentage from Dilivery
-- group by customer_id

select round(sum(if(T.first_order_date = T.pref_date, 1, 0))*100/count(*), 2) 
as immediate_percentage 
from 
(
    select customer_id, min(order_date) as first_order_date, min(customer_pref_delivery_date) pref_date from Delivery
    group by customer_id
) T
