#pragma once
#include <afx.h>

/// <summary>
/// MFC日志类，封装常用的日志处理函数
/// </summary>
class Logcat :
	public CObject
{
protected:
	/// 日志文件的路径
	CString filepath;

	/// 日志文件对象
	CStdioFile file;

public:
	/// Logcat对象的构造函数
	/// <param name="path">日志文件的路径</param>
	/// <param name="truncate">是否覆盖上一次生成的日志</param>
	Logcat(CONST CString& path = "log.txt", BOOL truncate = FALSE);


	virtual ~Logcat();

	/// 获取日志文件所在路径
	/// <returns>日志文件所在路径的字符串表示</returns>
	CString GetLogFilePath();

	/// 设置日志文件所在路径
	/// <returns>如果成功设置日志文件路径则返回真</returns>
	BOOL SetLogFilePath(CONST CString& path);

	/// 记录指定级别的日志
	/// <param name="level">日志级别</param>
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID Log(CONST CString& level, CONST CString& tag, CONST CString& voice);

	/// 输出Verbose级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID Verbose(CONST CString& tag, CONST CString& voice);

	/// 输出Verbose级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID V(CONST CString& tag, CONST CString& voice);
	
	/// 输出Debug级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID Debug(CONST CString& tag, CONST CString& voice);

	/// 输出Debug级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID D(CONST CString& tag, CONST CString& voice);

	/// 输出Info级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID Info(CONST CString& tag, CONST CString& voice);

	/// 输出Info级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>	
	VOID I(CONST CString& tag, CONST CString& voice);

	/// 输出Warn级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID Warn(CONST CString& tag, CONST CString& voice);
	
	/// 输出Warn级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID W(CONST CString& tag, CONST CString& voice);

	/// 输出Error级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID Error(CONST CString& tag, CONST CString& voice);
	
	/// 输出Error级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID E(CONST CString& tag, CONST CString& voice);


	///  输出Assert级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID Assert(CONST CString& tag, CONST CString& voice);

	///  输出Assert级别日志
	/// <param name="tag">日志标签</param>
	/// <param name="voice">日志内容</param>
	VOID A(CONST CString& tag, CONST CString& voice);
};
