#pragma once
#include <afx.h>


class CLogcat :
	public CObject
{
protected:
	// ��־�ļ���·��
	CString log_file_path;

	// ��־�ļ�����
	CStdioFile log_file;

public:
	// Ĭ�Ϲ��캯�����ڳ����Ŀ¼������־�ļ���log.txt��
	CLogcat();

	virtual ~CLogcat();

	// ��ȡ��־�ļ�����·��
	CString GetLogFilePath();

	// ������־�ļ�����·��
	BOOL SetLogFilePath(CONST CString& path);

	// ���Verbose������־
	VOID Verbose(CONST CString& voice);
	VOID V(CONST CString& voice);
	
	// ���Debug������־
	VOID Debug(CONST CString& voice);
	VOID D(CONST CString& voice);

	// ���Info������־
	VOID Info(CONST CString& voice);
	VOID I(CONST CString& voice);


	// ���Warn������־
	VOID Warn(CONST CString& voice);
	VOID W(CONST CString& voice);


	// ���Error������־
	VOID Error(CONST CString& voice);
	VOID E(CONST CString& voice);
};

