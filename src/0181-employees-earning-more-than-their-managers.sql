-- 181. Employees Earning More Than Their Managers
-- https://leetcode.com/problems/employees-earning-more-than-their-managers/

SELECT e.name AS Employee
FROM Employee e LEFT JOIN Employee m ON e.managerId = m.id
WHERE e.salary > m.salary;
