#include "logcat.h"


CLogcat::CLogcat()
{
	log_file_path = "log.txt";
	log_file.Open(log_file_path, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	log_file.WriteString("Success");
}

CLogcat::~CLogcat()
{
	log_file.Close();
}


CString CLogcat::GetLogFilePath()
{
	return log_file_path;
}


BOOL CLogcat::SetLogFilePath(CONST CString& path)
{
	log_file_path = path;
	log_file.Open(log_file_path, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	return TRUE;
}


VOID CLogcat::Verbose(const CString & voice)
{
	log_file.WriteString("[Verbose]" + voice);
}


VOID CLogcat::V(const CString & voice)
{
	Verbose(voice);
}

VOID CLogcat::Debug(const CString & voice)
{
	log_file.WriteString("[Debug]" + voice);
}

VOID CLogcat::D(const CString & voice)
{
	return VOID();
}

VOID CLogcat::I(const CString & voice)
{
	return VOID();
}

VOID CLogcat::Info(const CString & voice)
{
	log_file.WriteString("[Info]" + voice);
}


VOID CLogcat::Warn(const CString & voice)
{
	log_file.WriteString("[Warn]" + voice);
}


VOID CLogcat::W(const CString & voice)
{
	Warn(voice);
}


VOID CLogcat::Error(CONST CString& voice)
{
	log_file.WriteString("[Error]" + voice);
}


VOID CLogcat::E(const CString & voice)
{
	Error(voice);
}
