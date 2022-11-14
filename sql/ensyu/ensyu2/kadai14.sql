SELECT
    teacher,
    teachers.kyoka,
    AVG(seiseki.tokuten) AS avg
FROM teachers
    LEFT OUTER JOIN seiseki ON teachers.kyoka = seiseki.kyoka
GROUP BY kyoka