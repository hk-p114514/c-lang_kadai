CREATE TABLE `seiseki` (
 `id` int(11) NOT NULL AUTO_INCREMENT,
 `student_no` varchar(10) NOT NULL,
 `kyoka` varchar(10) NOT NULL,
 `tokuten` int(11) NOT NULL,
 PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8

CREATE TABLE `students` (
 `student_no` varchar(10) NOT NULL,
 `class` varchar(3) NOT NULL,
 `name` varchar(20) NOT NULL,
 `sex` varchar(2) NOT NULL,
 PRIMARY KEY (`student_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8

CREATE TABLE `teachers` (
 `class` varchar(2) NOT NULL,
 `teacher` varchar(5) NOT NULL,
 `kyoka` varchar(5) NOT NULL,
 PRIMARY KEY (`class`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8

CREATE TABLE `ei2030`. ( `class` VARCHAR(2) NOT NULL , `teacher` VARCHAR(10) NOT NULL , `kyoka` VARCHAR(10) NOT NULL , PRIMARY KEY (`class`)) ENGINE = InnoDB;

