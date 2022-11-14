SELECT name, kyoka, tokuten
FROM students RIGHT OUTER JOIN seiseki ON
students.student_no = seiseki.student_no
WHERE kyoka is not null;

