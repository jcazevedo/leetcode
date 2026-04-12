-- 177. Nth Highest Salary
-- https://leetcode.com/problems/nth-highest-salary/

CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  IF N > 0 THEN
    RETURN QUERY (
      SELECT DISTINCT e.salary
      FROM Employee e
      ORDER BY e.salary DESC
      LIMIT 1 OFFSET N - 1
    );
  END IF;
END;
$$ LANGUAGE plpgsql;
