-- 
-- @lc app=leetcode.cn id=1741 lang=mysql
--
-- [1741] 查找每个员工花费的总时间
--

-- @lc code=start
# Write your MySQL query statement below
SELECT event_day AS day, emp_id, SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY event_day, emp_id;
-- @lc code=end