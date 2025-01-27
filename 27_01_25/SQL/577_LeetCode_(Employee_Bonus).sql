/*
The goal of this SQL query is to retrieve employee names and their corresponding bonuses, ensuring that:

Employees without a bonus are also included.
Employees who have a bonus of less than 1000 are selected.
The result set should display the employee's name and bonus.

Selects the name column from the Employee table and the bonus column from the Bonus table.
The query begins by selecting records from the Employee table (as it contains all employees).
A LEFT JOIN ensures all records from the Employee table are retrieved, even if no matching record exists in the Bonus table.
The USING (empId) clause simplifies the join condition, assuming both tables have a common column empId.
Equivalent to: ON Employee.empId = Bonus.empId
This condition ensures that:
Employees with bonuses less than 1000 are selected.
Employees without any bonus (resulting in NULL values after the join) are also selected.
*/



-- SELECT e.name, b.bonus
-- FROM Employee e
-- LEFT JOIN Bonus b ON e.empId = b.empId
-- WHERE b.bonus < 1000 OR b.bonus IS NULL;

SELECT name,bonus
FROM Employee
LEFT JOIN  Bonus
USING (empId)
WHERE bonus < 1000 OR bonus IS NULL;