// RankDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SejongMine.h"
#include "RankDlg.h"
#include "afxdialogex.h"


// CRankDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CRankDlg, CDialogEx)

CRankDlg::CRankDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRankDlg::IDD, pParent)
	, m_strLevel(_T(""))
	, m_strName1(_T(""))
	, m_strName2(_T(""))
	, m_strName3(_T(""))
	, m_nTime1(0)
	, m_nTime2(0)
	, m_nTime3(0)
{

}

CRankDlg::~CRankDlg()
{
}

void CRankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LEVEL, m_strLevel);
	DDX_Text(pDX, IDC_NAME1, m_strName1);
	DDX_Text(pDX, IDC_NAME2, m_strName2);
	DDX_Text(pDX, IDC_NAME3, m_strName3);
	DDX_Text(pDX, IDC_TIME1, m_nTime1);
	DDX_Text(pDX, IDC_TIME2, m_nTime2);
	DDX_Text(pDX, IDC_TIME3, m_nTime3);
}


BEGIN_MESSAGE_MAP(CRankDlg, CDialogEx)
END_MESSAGE_MAP()


// CRankDlg 메시지 처리기입니다.
