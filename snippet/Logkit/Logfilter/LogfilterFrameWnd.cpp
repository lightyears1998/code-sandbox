#include "stdafx.h"
#include "LogfilterFrameWnd.h"


IMPLEMENT_DYNCREATE(LogfilterFrameWnd, CFrameWndEx)


LogfilterFrameWnd::LogfilterFrameWnd()
{
	Create(NULL, TEXT("日志过滤器"), WS_OVERLAPPEDWINDOW, CRect(0, 0, 480, 320));
}

LogfilterFrameWnd::~LogfilterFrameWnd()
{
}


BEGIN_MESSAGE_MAP(LogfilterFrameWnd, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void LogfilterFrameWnd::OnPaint()
{
	CPaintDC dc(this);
	CRect rect; GetClientRect(&rect);
	dc.DrawText(TEXT("Happy new year!"), rect, 0);
}
