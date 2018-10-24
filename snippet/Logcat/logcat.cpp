#include "logcat.h"


CLogcat::CLogcat(CONST CString& path, BOOL truncate)
{
	filepath = path;
	file.Open(filepath, CFile::modeCreate | (truncate ? 0U : CFile::modeNoTruncate) | CFile::modeWrite);
	file.SeekToEnd();
	Verbose("Logging util started");
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


VOID CLogcat::Log(CONST CString& level, CONST CString& voice)
{
	CString stamp;
	CTime time = CTime::GetCurrentTime();
	stamp.Format(TEXT("%d-%d %02d:%02d:%02d [%s] "), 
		time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond(),
		level);
	
	file.WriteString(stamp + voice + "\n");
}


VOID CLogcat::Verbose(const CString & voice)
{
	Log("Verbose", voice);
}


VOID CLogcat::V(const CString & voice)
{
	Verbose(voice);
}


VOID CLogcat::Debug(const CString & voice)
{
	Log("Debug", voice);
}


VOID CLogcat::D(const CString & voice)
{
	Debug(voice);
}


VOID CLogcat::Info(const CString & voice)
{
	Log("Info", voice);
}


VOID CLogcat::I(const CString & voice)
{
	Info(voice);
}


VOID CLogcat::Warn(const CString & voice)
{
	Log("Warn", voice);
}


VOID CLogcat::W(const CString & voice)
{
	Warn(voice);
}


VOID CLogcat::Error(CONST CString& voice)
{
	Log("Error", voice);
}


VOID CLogcat::E(const CString & voice)
{
	Error(voice);
}
