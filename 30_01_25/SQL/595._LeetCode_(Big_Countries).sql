/*
Approach

The query fetches country names along with their population and area from the World table, satisfying certain conditions.

Selects the columns name, population, and area from the World table.

Specifies that the data is retrieved from the World table

Condition 1: area >= 3000000: Selects countries with an area greater than or equal to 3 million square kilometers.
Condition 2: population >= 25000000: Selects countries with a population of at least 25 million.
Logical Operator (OR): Ensures that rows meeting either of the conditions are included.


*/

SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000;