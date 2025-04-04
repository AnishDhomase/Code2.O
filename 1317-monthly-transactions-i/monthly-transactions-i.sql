select 
date_format(trans_date, '%Y-%m') month,
country,
count(id) as trans_count,
sum(if(state="approved", 1, 0)) as approved_count,
sum(amount) as trans_total_amount,
sum(if(state="approved", amount, 0)) approved_total_amount
from Transactions 
group by month, country
