SELECT point,
	SUM(distance)
FROM traffic
GROUP BY point