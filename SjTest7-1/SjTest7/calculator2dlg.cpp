// calculator2dlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "calculator2dlg.h"
#include "afxdialogex.h"


// CCalculator2Dlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCalculator2Dlg, CDialogEx)

CCalculator2Dlg::CCalculator2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculator2Dlg::IDD, pParent)
{

}

CCalculator2Dlg::~CCalculator2Dlg()
{
}

void CCalculator2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCalculator2Dlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculator2Dlg 메시지 처리기입니다.
