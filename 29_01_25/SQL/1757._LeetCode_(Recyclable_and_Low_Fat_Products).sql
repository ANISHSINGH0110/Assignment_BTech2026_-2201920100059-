/*
The problem requires fetching unique product IDs where both low_fats and recyclable conditions are met.

Use SELECT DISTINCT to ensure no duplicate product IDs appear in the output. This avoids redundant results in the query output

The WHERE clause filters products that satisfy both conditions:
low_fats = 'Y': Selects only products marked as low-fat.
recyclable = 'Y': Selects only recyclable products.

*/




# Write your MySQL query statement below
SELECT DISTINCT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';