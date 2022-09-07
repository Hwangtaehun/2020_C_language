// UiThread2.cpp: 구현 파일
//
//#include "stdafx.h"
#include "pch.h"
#include "SjThread3.h"
#include "UiThread2.h"
#include "UiThreadWnd.h"

// CUiThread2

IMPLEMENT_DYNCREATE(CUiThread2, CWinThread)

CUiThread2::CUiThread2()
{
}

CUiThread2::~CUiThread2()
{
}

BOOL CUiThread2::InitInstance()
{
	// TODO:  여기에서 각 스레드에 대한 초기화를 수행합니다.
	m_pMainWnd = new CUiThreadWnd;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CUiThread2::ExitInstance()
{
	// TODO:  여기에서 각 스레드에 대한 정리를 수행합니다.
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUiThread2, CWinThread)
END_MESSAGE_MAP()


// CUiThread2 메시지 처리기
