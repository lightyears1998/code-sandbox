#include <afxwin.h>

class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

CHelloApp theApp;

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame() {
		Create(NULL, "ÎÒµÄ´°¿Ú", WS_OVERLAPPEDWINDOW, CRect(0, 0, 480, 320));
	}

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	CRect	 rc;
	GetClientRect(&rc);
	dc.DrawText(TEXT("Hello MFC!"), -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

BOOL CHelloApp::InitInstance()
{
	m_pMainWnd = new CMainFrame();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
