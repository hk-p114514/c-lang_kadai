SELECT class, AVG(tokuten)
FROM students
    LEFT OUTER JOIN seiseki ON students.student_no = seiseki.student_no
GROUP BY class