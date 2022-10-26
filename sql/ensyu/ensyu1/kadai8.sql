SELECT date,
	time,
	point
FROM traffic
WHERE point LIKE '%音羽%'
	OR point LIKE '%小牧%'