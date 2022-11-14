SELECT
    students.student_no,
    teachers.class,
    teachers.teacher,
    students.name
FROM students
    RIGHT OUTER JOIN teachers ON students.class = teachers.class