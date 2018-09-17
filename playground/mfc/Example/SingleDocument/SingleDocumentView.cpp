// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// SingleDocumentView.cpp: CSingleDocumentView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SingleDocument.h"
#endif

#include "SingleDocumentDoc.h"
#include "SingleDocumentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDocumentView

IMPLEMENT_DYNCREATE(CSingleDocumentView, CView)

BEGIN_MESSAGE_MAP(CSingleDocumentView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSingleDocumentView 构造/析构

CSingleDocumentView::CSingleDocumentView() noexcept
{
	// TODO: 在此处添加构造代码

}

CSingleDocumentView::~CSingleDocumentView()
{
}

BOOL CSingleDocumentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSingleDocumentView 绘图

void CSingleDocumentView::OnDraw(CDC* /*pDC*/)
{
	CSingleDocumentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CSingleDocumentView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSingleDocumentView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSingleDocumentView 诊断

#ifdef _DEBUG
void CSingleDocumentView::AssertValid() const
{
	CView::AssertValid();
}

void CSingleDocumentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSingleDocumentDoc* CSingleDocumentView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDocumentDoc)));
	return (CSingleDocumentDoc*)m_pDocument;
}
#endif //_DEBUG


// CSingleDocumentView 消息处理程序
