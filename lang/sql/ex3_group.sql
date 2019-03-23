SELECT gradeId '年级', sex '性别', count(*) '人数'
FROM student
GROUP BY gradeId, sex;
