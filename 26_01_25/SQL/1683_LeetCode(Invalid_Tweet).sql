/*
Approach


For this SQL query, the goal is to retrieve all tweet_id values from the Tweets table where the length of the tweet content exceeds 15 characters.

*/


SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;