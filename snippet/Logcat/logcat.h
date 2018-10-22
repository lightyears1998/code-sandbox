#pragma once
#include <afx.h>


class CLogcat :
	public CObject
{
protected:
	/// 日志文件的路径
	CString filepath;

	/// 日志文件对象
	CStdioFile file;

	/// 时间对象
	CTime time;

public:
	/// CLogcat对象的构造函数
	/// <param name="path">日志文件的路径</param>
	/// <param name="truncate">是否覆盖上一次生成的日志</param>
	CLogcat(CONST CString& path = "log.txt", BOOL truncate = FALSE);


	virtual ~CLogcat();

	/// 获取日志文件所在路径
	CString GetLogFilePath();

	/// 设置日志文件所在路径
	BOOL SetLogFilePath(CONST CString& path);

	/// 输出Verbose级别日志
	VOID Verbose(CONST CString& voice);

	/// 输出Verbose级别日志
	VOID V(CONST CString& voice);
	
	/// 输出Debug级别日志
	VOID Debug(CONST CString& voice);

	/// 输出Debug级别日志
	VOID D(CONST CString& voice);

	/// 输出Info级别日志
	VOID Info(CONST CString& voice);

	/// 输出Info级别日志
	VOID I(CONST CString& voice);

	/// 输出Warn级别日志
	VOID Warn(CONST CString& voice);
	
	/// 输出Warn级别日志
	VOID W(CONST CString& voice);

	/// 输出Error级别日志
	VOID Error(CONST CString& voice);
	
	/// 输出Error级别日志
	VOID E(CONST CString& voice);
};
