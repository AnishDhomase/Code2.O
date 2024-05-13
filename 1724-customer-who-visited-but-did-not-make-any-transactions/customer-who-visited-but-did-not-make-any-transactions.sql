# Write your MySQL query statement below

select Visits.customer_id, count(Visits.visit_id) as count_no_trans from Visits
left join (
select visit_id, count(transaction_id) as ct from Transactions
group by visit_id 
) as A
on A.visit_id = Visits.visit_id
where ct is NULL
group by Visits.customer_id
