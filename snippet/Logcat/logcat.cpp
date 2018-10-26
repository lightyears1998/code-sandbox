#include "logcat.h"


CLogcat::CLogcat(CONST CString& path, BOOL truncate)
{
	filepath = path;
	file.Open(filepath, CFile::modeCreate | (truncate ? 0U : CFile::modeNoTruncate) | CFile::modeWrite);
	file.SeekToEnd();
	Verbose("LogUtil", "Logging util started.");
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


VOID CLogcat::Log(CONST CString& level, CONST CString& tag, CONST CString& voice)
{
	CString stamp;
	CTime time = CTime::GetCurrentTime();
	stamp.Format(TEXT("%d-%d %02d:%02d:%02d %s/%s: "), 
		time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond(),
		level, tag);
	
	file.WriteString(stamp + voice + "\n");
}


VOID CLogcat::Verbose(CONST CString& tag, const CString & voice)
{
	Log("V", tag, voice);
}


VOID CLogcat::V(CONST CString& tag, const CString & voice)
{
	Verbose(tag, voice);
}


VOID CLogcat::Debug(CONST CString& tag, const CString & voice)
{
	Log("D", tag, voice);
}


VOID CLogcat::D(CONST CString& tag, const CString & voice)
{
	Debug(tag, voice);
}


VOID CLogcat::Info(CONST CString& tag, const CString & voice)
{
	Log("I", tag, voice);
}


VOID CLogcat::I(CONST CString& tag, const CString & voice)
{
	Info(tag, voice);
}


VOID CLogcat::Warn(CONST CString& tag, const CString & voice)
{
	Log("W", tag, voice);
}


VOID CLogcat::W(CONST CString& tag, CONST CString & voice)
{
	Warn(tag, voice);
}


VOID CLogcat::Error(CONST CString& tag, CONST CString& voice)
{
	Log("E", tag, voice);
}


VOID CLogcat::E(CONST CString& tag, CONST CString & voice)
{
	Error(tag, voice);
}

VOID CLogcat::Assert(const CString & tag, const CString & voice)
{
	Log("A", tag, voice);
}

VOID CLogcat::A(const CString & tag, const CString & voice)
{
	Assert(tag, voice);
}
