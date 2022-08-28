// CustomDlg.cpp: 구현 파일
//

#include "stdafx.h"
//#include "pch.h"
#include "SejongMine.h"
#include "CustomDlg.h"
#include "afxdialogex.h"


// CCustomDlg 대화 상자

IMPLEMENT_DYNAMIC(CCustomDlg, CDialogEx)

CCustomDlg::CCustomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_nHeight(0)
	, m_nWidth(0)
	, m_nMine(0)
{

}

CCustomDlg::~CCustomDlg()
{
}

void CCustomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_nHeight);
	DDV_MinMaxInt(pDX, m_nHeight, 1, 24);
	DDX_Text(pDX, IDC_EDIT_WIDTH, m_nWidth);
	DDV_MinMaxInt(pDX, m_nWidth, 1, 30);
	DDX_Text(pDX, IDC_EDIT_MINE, m_nMine);
}


BEGIN_MESSAGE_MAP(CCustomDlg, CDialogEx)
END_MESSAGE_MAP()


// CCustomDlg 메시지 처리기
