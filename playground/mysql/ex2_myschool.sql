CREATE DATABASE myschool;
USE myschool;

// 创建表

CREATE TABLE IF NOT EXISTS subject (
    subjectNo INT(4) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    subjectName VARCHAR(50),
    classHour INT(4),
    gradeID INT(4)
) COMMENT='科目表';

CREATE TABLE IF NOT EXISTS result (
    studentNo INT(4) NOT NULL,
    subjectNo INT(4) NOT NULL,
    examDate DATETIME NOT NULL,
    studentResult INT(4) NOT NULL
) COMMENT='成绩表';

CREATE TABLE IF NOT EXISTS student (
    studentNo INT(4) NOT NULL PRIMARY KEY,
    loginPwd VARCHAR(20) NOT NULL,
    studentName VARCHAR(50) NOT NULL,
    sex CHAR(2) NOT NULL, 
    gradeID INT(4) UNSIGNED,
    phone VARCHAR(50),
    address VARCHAR(255),
    birthday DATETIME,
    email VARCHAR(50),
    identityCard VARCHAR(18)
) COMMENT='学生信息表'; 

CREATE TABLE IF NOT EXISTS grade (
    gradeID INT(4) PRIMARY KEY  NOT NULL AUTO_INCREMENT,
    gradeName VARCHAR(50)
) COMMENT='年级表';

// 向表中插入数据

INSERT INTO subject (subjectNo, subjectName, classHour, gradeID) VALUES
(1, 'LogicJava', 220, 1), 
(2, 'HTML', 160, 1),
(3, 'JavaOOP', 230, 2);

INSERT INTO student (studentNo, loginPwd, studentName, sex, gradeID, phone, address, birthday) VALUES
(10000, '123', '郭靖', '男', 1, '13645667783', '天津市河西区', '1990.9.8'),
(10001, '123', '李文才', '男', 1, '13645667890', '地址不详', '1994.4.12'),
(10002, '123', '李斯文', '男', 1, '13645556793', '河南洛阳', '1993.7.23'),
(10003, '123', '张萍', '女', 1, '136423451122', '地址不详', '1995.6.10'),
(10004, '123', '韩秋洁', '女', 1, '13812344566', '北京市海淀区', '1995.7.15'),
(10005, '123', '张秋丽', '女', 1, '13567893246', '北京市东城区', '1994.1.17'),
(10006, '123', '肖梅', '女', 1, '13563456721', '河北省石家庄市', '1991.2.17'),
(10007, '123', '秦洋', '男', 1, '13056434411', '上海市卢湾区', '1992.4.18'),
(10008, '123', '何晴晴', '女', 1, '13056434411', '广州市天河区', '1997.7.23'),
(20000, '123', '王宝宝', '男', 2, '15076552323', '地址不详', '1996.6.5'),
(20010, '123', '何小华', '女', 2, '13318877954', '地址不详', '1995.9.10'),
(30011, '123', '陈志强', '女', 3, '13689965430', '地址不详', '1994.9.27'),
(30012, '123', '李露露', '女', 3, '13685678854', '地址不详', '1992.9.27');

// 插入随机生成的数据（ex2_data_gen.cpp）
