-- seiseki

INSERT INTO
    seiseki (id, student_no, kyoka, tokuten)
VALUES (NULL, '2022-001', '国語', '75');

-- teachers

INSERT INTO
    teachers (class, teacher, kyoka)
VALUES ('A', '福沢', '理科'), ('B', '樋口' '国語'), ('C', '野口', '社会'), ('D', '岩倉', '算数');

-- students

INSERT INTO
    `ei2030`.`students` (
        `student_no`,
        `class`,
        `name`,
        `sex`
    )
VALUES ('2022-003', 'C', '鈴木一郎', '男');