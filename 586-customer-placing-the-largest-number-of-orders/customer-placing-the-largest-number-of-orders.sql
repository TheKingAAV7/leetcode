SELECT x.customer_number
FROM (
    SELECT o.customer_number, COUNT(*) AS cnt
    FROM Orders o
    GROUP BY o.customer_number
) x
WHERE x.cnt = (SELECT MAX(cnt) FROM (
                    SELECT COUNT(*) AS cnt
                    FROM Orders
                    GROUP BY customer_number
                ) as y);
