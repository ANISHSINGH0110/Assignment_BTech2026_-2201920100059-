/*
Fetch data from Cinema.
Apply filters (MOD(id, 2) = 1 and description != 'boring').
Sort the filtered rows in descending order based on rating.
Return all columns for the resulting rows.
This query efficiently selects only relevant, non-"boring" movies with odd IDs and orders them by popularity or rating.
*/
SELECT *
FROM Cinema
WHERE
  MOD(id, 2) = 1
  AND description != 'boring'
ORDER BY rating DESC;