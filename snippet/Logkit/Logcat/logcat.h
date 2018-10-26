#pragma once
#include <afx.h>

/// <summary>
/// MFC��־�࣬��װ���õ���־������
/// </summary>
class Logcat :
	public CObject
{
protected:
	/// ��־�ļ���·��
	CString filepath;

	/// ��־�ļ�����
	CStdioFile file;

public:
	/// Logcat����Ĺ��캯��
	/// <param name="path">��־�ļ���·��</param>
	/// <param name="truncate">�Ƿ񸲸���һ�����ɵ���־</param>
	Logcat(CONST CString& path = "log.txt", BOOL truncate = FALSE);


	virtual ~Logcat();

	/// ��ȡ��־�ļ�����·��
	/// <returns>��־�ļ�����·�����ַ�����ʾ</returns>
	CString GetLogFilePath();

	/// ������־�ļ�����·��
	/// <returns>����ɹ�������־�ļ�·���򷵻���</returns>
	BOOL SetLogFilePath(CONST CString& path);

	/// ��¼ָ���������־
	/// <param name="level">��־����</param>
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID Log(CONST CString& level, CONST CString& tag, CONST CString& voice);

	/// ���Verbose������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID Verbose(CONST CString& tag, CONST CString& voice);

	/// ���Verbose������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID V(CONST CString& tag, CONST CString& voice);
	
	/// ���Debug������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID Debug(CONST CString& tag, CONST CString& voice);

	/// ���Debug������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID D(CONST CString& tag, CONST CString& voice);

	/// ���Info������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID Info(CONST CString& tag, CONST CString& voice);

	/// ���Info������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>	
	VOID I(CONST CString& tag, CONST CString& voice);

	/// ���Warn������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID Warn(CONST CString& tag, CONST CString& voice);
	
	/// ���Warn������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID W(CONST CString& tag, CONST CString& voice);

	/// ���Error������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID Error(CONST CString& tag, CONST CString& voice);
	
	/// ���Error������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID E(CONST CString& tag, CONST CString& voice);


	///  ���Assert������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID Assert(CONST CString& tag, CONST CString& voice);

	///  ���Assert������־
	/// <param name="tag">��־��ǩ</param>
	/// <param name="voice">��־����</param>
	VOID A(CONST CString& tag, CONST CString& voice);
};
