/*
The task is to retrieve the names of classes from the Courses table that have at least 5 associated rows (entries).

This selects the column class from the Courses table, which stores class information.
Specifies the table from which data will be selected.
Groups the rows of the table by unique values in the class column.
This aggregation allows counting the number of rows in each class.
Filters the groups to include only those where the number of rows (COUNT(*)) is 5 or more.
HAVING is used here because conditions on aggregate functions (COUNT) must be specified in the HAVING clause rather than WHERE.
*/

SELECT class
FROM Courses
GROUP BY 1
HAVING COUNT(*) >= 5;