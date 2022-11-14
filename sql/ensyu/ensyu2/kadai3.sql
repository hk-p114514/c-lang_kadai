SELECT name, kyoka, tokuten
FROM students INNER JOIN seiseki ON
students.student_no = seiseki.student_no;

