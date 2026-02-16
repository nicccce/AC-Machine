-- 
-- @lc app=leetcode.cn id=1378 lang=mysql
--
-- [1378] 使用唯一标识码替换员工ID
--

-- @lc code=start
# Write your MySQL query statement below
SELECT eu.unique_id, e.name
FROM Employees e
LEFT JOIN EmployeeUNI eu ON e.id = eu.id;
-- @lc code=end