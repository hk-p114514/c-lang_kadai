SELECT date,
	direction,
	point
FROM traffic
WHERE date = '2022-09-13'
	AND date NOT = '2022-09-14'
	or date = '2022-09-14'
	AND date NOT = '2022-09-13'