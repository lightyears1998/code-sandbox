#pragma once


class LogfilterFrameWnd : public CFrameWnd
{
public:
	LogfilterFrameWnd();
	virtual ~LogfilterFrameWnd();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();

private:
	CListCtrl listCtrl;
};


