const sqlTemplate =
  "INSERT INTO `seiseki` (`id`, `student_no`, `kyoka`, `tokuten`) VALUES (NULL, '2022-001', '国語', '75')";

const studentNumber = [
  "2022-001",
  "2022-001",
  "2022-001",
  "2022-002",
  "2022-002",
  "2022-003",
  "2022-004",
  "2022-004",
];

const subjects = [
  //
  "国語",
  "算数",
  "理科",
  "国語",
  "算数",
  "理科",
  "国語",
  "理科",
];

const scores = [75, 80, 78, 68, 73, 83, 62, 93];

const genFromTemplate = (studentNumber, subject, score) => {
  console.log(
    `INSERT INTO seiseki (id, student_no, kyoka, tokuten) VALUES (NULL, '${studentNumber}', '${subject}', '${score}');`,
  );
};

for (let i = 0; i < 8; i++) {
  genFromTemplate(studentNumber[i], subjects[i], scores[i]);
}
