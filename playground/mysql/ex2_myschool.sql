CREATE DATABASE School;
USE School;

CREATE TABLE IF NOT EXISTS subject (
    id INT PRIMARY KEY NOT NULL, 
    projectName VARCHAR(20),
    classHour INT,
    termNumber INT
);

CREATE TABLE IF NOT EXISTS student (
    studentCode INT PRIMARY KEY, 
    password VARCHAR(20),
    name VARCHAR(10),
    sex CHAR(1),
    gradeCode INT,
    phone VARCHAR(20),
    address VARCHAR(50),
    birthday DATE
);

// 为科目表、学生表和成绩表添加数据

INSERT INTO subject (id, projectName, classHour, termNumber) VALUES
(1, 'LogicJava', 220, 1), 
(2, 'HTML', 160, 1),
(3, 'JavaOOP', 230, 2);

INSERT INTO student (studentCode, password, name, sex, gradeCode, phone, address, birthday) VALUES
(10000, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(10001, '123', '李文才', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(10002, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(10003, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(10004, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(10005, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(10006, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(10007, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(10008, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(20000, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(20010, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(30011, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8'),
(30012, '123', '郭靖', '男', 1, '1364566783', '天津市河西区', '1990.9.8');
