# Write your MySQL query statement below
select E.name from
(
    select E.managerId from Employee E
    where E.managerId is not null
    group by E.managerId
    having count(E.id) >= 5
) as T
join Employee E
on T.managerId = E.id
