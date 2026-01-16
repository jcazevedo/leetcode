-- 176. Second Highest Salary
-- https://leetcode.com/problems/second-highest-salary/

SELECT MAX(e.salary) AS SecondHighestSalary
FROM Employee e LEFT JOIN (SELECT MAX(salary) AS salary FROM Employee) m ON e.salary = m.salary
WHERE m.salary IS NULL;
