SELECT
  name,
  kyoka,
  tokuten
FROM
  students,
  seiseki
WHERE
  students.student_no = seiseki.student_no
