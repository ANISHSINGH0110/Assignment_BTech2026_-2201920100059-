/*
The task is to calculate the percentage of users registered for each contest 
in the Register table compared to the total number of users in the Users table, rounded to two decimal places.

*/
SELECT
  contest_id,
  ROUND(
    COUNT(user_id) * 100 / (
      SELECT COUNT(*)
      FROM Users
    ),
    2
  ) AS percentage
FROM Register
GROUP BY 1
ORDER BY percentage DESC, contest_id;