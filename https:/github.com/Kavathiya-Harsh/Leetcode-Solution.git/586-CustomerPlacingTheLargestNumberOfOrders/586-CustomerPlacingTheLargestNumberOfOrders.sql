-- Last updated: 8/11/2026, 2:12:03 PM
# Write your MySQL query statement below
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;