/*
SELECT Project.project_id: Selects the project ID.
ROUND(AVG(Employee.experience_years), 2): Computes the average employee experience years per project and rounds it to two decimal places.
INNER JOIN USING (employee_id): Combines the Project and Employee tables based on the employee_id.
GROUP BY 1: Groups the data by the first column, which is project_id.
*/
SELECT
  Project.project_id,
  ROUND(AVG(Employee.experience_years), 2) AS average_years
FROM Project
INNER JOIN Employee
  USING (employee_id)
GROUP BY 1;