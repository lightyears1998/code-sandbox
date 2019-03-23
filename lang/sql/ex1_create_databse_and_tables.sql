CREATE DATABASE Library;
USE Library;

CREATE TABLE IF NOT EXISTS book (
    bid CHAR PRIMARY KEY NOT NULL COMMENT '图书编号',
    bName CHAR NOT NULL COMMENT '图书书名',
    author CHAR COMMENT '作者姓名',
    pubComp CHAR COMMENT '出版社',
    pubDate DATE COMMENT '出版日期',
    bCount INT COMMENT '现存数量',
    price DOUBLE COMMENT '单价'
) COMMENT='图书信息表' CHARSET=utf8; 

CREATE TABLE IF NOT EXISTS reader (
    Rid CHAR PRIMARY KEY NOT NULL COMMENT '读者编号',
    rName CHAR NOT NULL COMMENT '读者姓名',
    lendNum INT COMMENT '已借书数量',
    rAddress CHAR COMMENT '联系地址'
) COMMENT='' CHARSET=utf8;

CREATE TABLE IF NOT EXISTS borrow (
    rid CHAR NOT NULL COMMENT '读者编号',
    nif CHAR NOT NULL COMMENT '图书编号',
    lendDate TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT '借阅日期',
    willDate DATETIME COMMENT '应归还日期' ,
    returnDate DATETIME COMMENT '实际归还日期',
    PRIMARY KEY(rid, nif, lendDate)
) COMMENT='图书借阅表' CHARSET=utf8;

CREATE TABLE IF NOT EXISTS penalty (
    rid CHAR NOT NULL COMMENT '读者编号',    
    bid CHAR NOT NULL COMMENT '图书编号',
    pDate DATETIME NOT NULL COMMENT '罚款日期',
    pType INT COMMENT '罚款类型',
    amount DOUBLE COMMENT '罚款金额'
) COMMENT='罚款记录表' CHARSET=utf8;
