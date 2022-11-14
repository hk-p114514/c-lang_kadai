SELECT
    class,
    name,
    AVG(seiseki.tokuten)
FROM students
    LEFT OUTER JOIN seiseki ON students.student_no = seiseki.student_no
WHERE
    seiseki.tokuten IS NOT null
GROUP BY seiseki.student_no