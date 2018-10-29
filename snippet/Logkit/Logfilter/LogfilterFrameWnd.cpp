#include "stdafx.h"
#include "LogfilterFrameWnd.h"


LogfilterFrameWnd::LogfilterFrameWnd()
{
	Create(NULL, TEXT("日志过滤器"), WS_OVERLAPPEDWINDOW, CRect(0, 0, 800, 600));
	listCtrl.Create(WS_CHILD | WS_VISIBLE |LVS_REPORT, CRect(0, 0, 320, 480), this, 1);
	listCtrl.InsertColumn(0, TEXT("栏目"));

	CenterWindow();
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
}
