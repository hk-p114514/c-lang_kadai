SELECT point,
	direction,
	SUM(distance),
	AVG(distance)
FROM traffic
GROUP BY point,
	direction
ORDER BY distance DESC