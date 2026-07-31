-- Last updated: 7/31/2026, 1:28:52 PM
# Write your MySQL query statement below
select email from Person group by email having count(*) > 1;