#pragma once
#include <afx.h>

/// <summary>
/// MFC日志类，封装常用的日志处理函数
/// </summary>
class CLogcat :
	public CObject
{
protected:
	/// 日志文件的路径
	CString filepath;

	/// 日志文件对象
	CStdioFile file;

public:
	/// CLogcat对象的构造函数
	/// <param name="path">日志文件的路径</param>
	/// <param name="truncate">是否覆盖上一次生成的日志</param>
	CLogcat(CONST CString& path = "log.txt", BOOL truncate = FALSE);


	virtual ~CLogcat();

	/// 获取日志文件所在路径
	/// <returns>日志文件所在路径的字符串表示</returns>
	CString GetLogFilePath();

	/// 设置日志文件所在路径
	/// <returns>如果成功设置日志文件路径则返回真</returns>
	BOOL SetLogFilePath(CONST CString& path);

	/// 记录指定级别的日志
	/// <param name="level">日志级别</param>
	/// <param name="voice">日志</param>
	VOID Log(CONST CString& level, CONST CString& voice);

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
