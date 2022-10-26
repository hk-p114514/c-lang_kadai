SELECT point,
	SUM(distance)
FROM traffic
GROUP BY point
HAVING SUM(distance) >= 50