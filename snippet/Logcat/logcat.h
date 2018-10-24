#pragma once
#include <afx.h>

/// <summary>
/// MFC��־�࣬��װ���õ���־������
/// </summary>
class CLogcat :
	public CObject
{
protected:
	/// ��־�ļ���·��
	CString filepath;

	/// ��־�ļ�����
	CStdioFile file;

public:
	/// CLogcat����Ĺ��캯��
	/// <param name="path">��־�ļ���·��</param>
	/// <param name="truncate">�Ƿ񸲸���һ�����ɵ���־</param>
	CLogcat(CONST CString& path = "log.txt", BOOL truncate = FALSE);


	virtual ~CLogcat();

	/// ��ȡ��־�ļ�����·��
	/// <returns>��־�ļ�����·�����ַ�����ʾ</returns>
	CString GetLogFilePath();

	/// ������־�ļ�����·��
	/// <returns>����ɹ�������־�ļ�·���򷵻���</returns>
	BOOL SetLogFilePath(CONST CString& path);

	/// ��¼ָ���������־
	/// <param name="level">��־����</param>
	/// <param name="voice">��־</param>
	VOID Log(CONST CString& level, CONST CString& voice);

	/// ���Verbose������־
	VOID Verbose(CONST CString& voice);

	/// ���Verbose������־
	VOID V(CONST CString& voice);
	
	/// ���Debug������־
	VOID Debug(CONST CString& voice);

	/// ���Debug������־
	VOID D(CONST CString& voice);

	/// ���Info������־
	VOID Info(CONST CString& voice);

	/// ���Info������־
	VOID I(CONST CString& voice);

	/// ���Warn������־
	VOID Warn(CONST CString& voice);
	
	/// ���Warn������־
	VOID W(CONST CString& voice);

	/// ���Error������־
	VOID Error(CONST CString& voice);
	
	/// ���Error������־
	VOID E(CONST CString& voice);
};
