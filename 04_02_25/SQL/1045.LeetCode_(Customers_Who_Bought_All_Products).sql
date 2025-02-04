/*
The task requires finding the customer_id from the Customer table where 
the number of distinct product_key purchased by the customer matches the total number of products in the Product table.
*/
SELECT customer_id
FROM Customer
GROUP BY 1
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*) FROM Product
  );