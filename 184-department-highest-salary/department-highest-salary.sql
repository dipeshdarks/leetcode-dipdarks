# Write your MySQL query statement below
SELECT
    d.name AS Department,
    t.name AS Employee,
    t.salary AS Salary
FROM (
    SELECT *,
           DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee
) t
JOIN Department d
    ON t.departmentId = d.id
WHERE t.rnk = 1;