/*
The task is to retrieve the number of followers for each user and display the results ordered by user_id. The Followers table contains two columns:

user_id: Represents the user.
follower_id: Represents the user who follows user_id.
Selects the user_id and counts the number of unique follower_id entries for each user_id.
COUNT(follower_id) counts only non-null follower entries, giving the total number of followers per user.
The result is aliased as followers_count.
*/
SELECT
  user_id,
  COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY 1
ORDER BY 1;