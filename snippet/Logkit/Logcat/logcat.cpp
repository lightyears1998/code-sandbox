#include "logcat.h"


Logcat::Logcat(CONST CString& path, BOOL truncate)
{
	filepath = path;
	file.Open(filepath, CFile::modeCreate | (truncate ? 0U : CFile::modeNoTruncate) | CFile::modeWrite);
	file.SeekToEnd();
	Verbose("LogUtil", "Logging util started.");
}


Logcat::~Logcat()
{
	file.Close();
}


CString Logcat::GetLogFilePath()
{
	return filepath;
}


BOOL Logcat::SetLogFilePath(CONST CString& path)
{
	filepath = path;
	file.Open(filepath, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	return TRUE;
}


VOID Logcat::Log(CONST CString& level, CONST CString& tag, CONST CString& voice)
{
	CString stamp;
	CTime time = CTime::GetCurrentTime();
	stamp.Format(TEXT("%d-%d %02d:%02d:%02d %s/%s: "), 
		time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond(),
		level, tag);
	
	file.WriteString(stamp + voice + "\n");
}


VOID Logcat::Verbose(CONST CString& tag, const CString & voice)
{
	Log("V", tag, voice);
}


VOID Logcat::V(CONST CString& tag, const CString & voice)
{
	Verbose(tag, voice);
}


VOID Logcat::Debug(CONST CString& tag, const CString & voice)
{
	Log("D", tag, voice);
}


VOID Logcat::D(CONST CString& tag, const CString & voice)
{
	Debug(tag, voice);
}


VOID Logcat::Info(CONST CString& tag, const CString & voice)
{
	Log("I", tag, voice);
}


VOID Logcat::I(CONST CString& tag, const CString & voice)
{
	Info(tag, voice);
}


VOID Logcat::Warn(CONST CString& tag, const CString & voice)
{
	Log("W", tag, voice);
}


VOID Logcat::W(CONST CString& tag, CONST CString & voice)
{
	Warn(tag, voice);
}


VOID Logcat::Error(CONST CString& tag, CONST CString& voice)
{
	Log("E", tag, voice);
}


VOID Logcat::E(CONST CString& tag, CONST CString & voice)
{
	Error(tag, voice);
}

VOID Logcat::Assert(const CString & tag, const CString & voice)
{
	Log("A", tag, voice);
}

VOID Logcat::A(const CString & tag, const CString & voice)
{
	Assert(tag, voice);
}
