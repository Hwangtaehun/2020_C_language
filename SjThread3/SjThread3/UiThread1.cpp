// UiThread1.cpp: 구현 파일
//
//#include "stdafx.h"
#include "pch.h"
#include "SjThread3.h"
#include "UiThread1.h"
#include "SjThread3Dlg.h"


// CUiThread1

IMPLEMENT_DYNCREATE(CUiThread1, CWinThread)

CUiThread1::CUiThread1()
{
}

CUiThread1::~CUiThread1()
{
}

BOOL CUiThread1::InitInstance()
{
	// TODO:  여기에서 각 스레드에 대한 초기화를 수행합니다.
	return TRUE;
}

int CUiThread1::ExitInstance()
{
	// TODO:  여기에서 각 스레드에 대한 정리를 수행합니다.
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUiThread1, CWinThread)
END_MESSAGE_MAP()


// CUiThread1 메시지 처리기


int CUiThread1::Run()
{
	// TODO: 여기에 구현 코드 추가.
	CSjThread3App* pApp = (CSjThread3App*)AfxGetApp();
	CSjThread3Dlg* pDlg = (CSjThread3Dlg*)pApp->m_pMainWnd;

	CString str;
	for (int a = 1; a < 1000; a++)
	{
		str.Format(_T("%7d "), a);
		pDlg->SetDlgItemText(IDC_EDIT1, str);
		Sleep(1);
	}
	pDlg->GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	return CWinThread::Run();
}
