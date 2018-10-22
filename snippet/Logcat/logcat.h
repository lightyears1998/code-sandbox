#pragma once
#include <afx.h>


class CLogcat :
	public CObject
{
protected:
	// 日志文件的路径
	CString log_file_path;

	// 日志文件对象
	CStdioFile log_file;

public:
	// 默认构造函数，在程序根目录创建日志文件“log.txt”
	CLogcat();

	virtual ~CLogcat();

	// 获取日志文件所在路径
	CString GetLogFilePath();

	// 设置日志文件所在路径
	BOOL SetLogFilePath(CONST CString& path);

	// 输出Verbose级别日志
	VOID Verbose(CONST CString& voice);
	VOID V(CONST CString& voice);
	
	// 输出Debug级别日志
	VOID Debug(CONST CString& voice);
	VOID D(CONST CString& voice);

	// 输出Info级别日志
	VOID Info(CONST CString& voice);
	VOID I(CONST CString& voice);


	// 输出Warn级别日志
	VOID Warn(CONST CString& voice);
	VOID W(CONST CString& voice);


	// 输出Error级别日志
	VOID Error(CONST CString& voice);
	VOID E(CONST CString& voice);
};

