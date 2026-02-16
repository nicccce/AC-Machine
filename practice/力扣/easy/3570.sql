-- 
-- @lc app=leetcode.cn id=3570 lang=mysql
--
-- [3570] 查找无可用副本的书籍
--

-- @lc code=start
# Write your MySQL query statement below
SELECT 
    lb.book_id,
    lb.title,
    lb.author,
    lb.genre,
    lb.publication_year,
    COUNT(br.record_id) AS current_borrowers
FROM library_books lb
LEFT JOIN borrowing_records br ON lb.book_id = br.book_id AND br.return_date IS NULL
GROUP BY lb.book_id, lb.title, lb.author, lb.genre, lb.publication_year, lb.total_copies
HAVING lb.total_copies = current_borrowers AND current_borrowers > 0
ORDER BY current_borrowers DESC, lb.title ASC;
-- @lc code=end