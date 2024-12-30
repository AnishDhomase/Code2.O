# Write your MySQL query statement below
select T.machine_id, round(avg(T.diff), 3) as processing_time from
(
    select a1.machine_id, a2.timestamp - a1.timestamp as diff from Activity a1, Activity a2
    where a1.machine_id = a2.machine_id and
    a1.process_id = a2.process_id and 
    a1.timestamp < a2.timestamp
) as T
group by a1.machine_id