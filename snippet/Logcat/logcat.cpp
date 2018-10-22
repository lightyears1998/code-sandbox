#include "logcat.h"


CLogcat::CLogcat(CONST CString& path, BOOL truncate)
{
	filepath = path;
	file.Open(filepath, CFile::modeCreate | (truncate ? 0U : CFile::modeNoTruncate) | CFile::modeWrite);
	file.SeekToEnd();
	file.WriteString("Success\n");
}


CLogcat::~CLogcat()
{
	file.Close();
}


CString CLogcat::GetLogFilePath()
{
	return filepath;
}


BOOL CLogcat::SetLogFilePath(CONST CString& path)
{
	filepath = path;
	file.Open(filepath, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	return TRUE;
}


VOID CLogcat::Verbose(const CString & voice)
{
	file.WriteString("[Verbose]" + voice);
}


VOID CLogcat::V(const CString & voice)
{
	Verbose(voice);
}


VOID CLogcat::Debug(const CString & voice)
{
	file.WriteString("[Debug]" + voice);
}


VOID CLogcat::D(const CString & voice)
{
	Debug(voice);
}


VOID CLogcat::Info(const CString & voice)
{
	file.WriteString("[Info]" + voice);
}


VOID CLogcat::I(const CString & voice)
{
	Info(voice);
}


VOID CLogcat::Warn(const CString & voice)
{
	file.WriteString("[Warn]" + voice);
}


VOID CLogcat::W(const CString & voice)
{
	Warn(voice);
}


VOID CLogcat::Error(CONST CString& voice)
{
	file.WriteString("[Error]" + voice);
}


VOID CLogcat::E(const CString & voice)
{
	Error(voice);
}
