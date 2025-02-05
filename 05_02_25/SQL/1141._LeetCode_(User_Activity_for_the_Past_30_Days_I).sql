/*
The task is to retrieve the number of unique active users per day within a specified date range. 
The results must show each day as a row with the count of distinct users.


*/
SELECT
  activity_date AS day,
  COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN '2019-06-28' AND  '2019-07-27'
GROUP BY 1;