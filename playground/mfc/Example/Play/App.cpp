#include "stdafx.h"

#include "App.h"
#include "Window.h"

App::App()
{

}

App::~App()
{

}


BOOL App::InitInstance()
{
	m_pMainWnd = new Window;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	
	return TRUE;
}

App theApp;
