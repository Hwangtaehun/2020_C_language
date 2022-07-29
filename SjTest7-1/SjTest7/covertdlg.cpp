// covertdlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "covertdlg.h"
#include "afxdialogex.h"


// CCovertDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCovertDlg, CDialogEx)

CCovertDlg::CCovertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCovertDlg::IDD, pParent)
	, m_nResult(_T(""))
{

}

CCovertDlg::~CCovertDlg()
{
}

void CCovertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nResult);
}


BEGIN_MESSAGE_MAP(CCovertDlg, CDialogEx)
	ON_COMMAND(IDC_HEX, &CCovertDlg::OnHex)
	ON_COMMAND(IDC_DEC, &CCovertDlg::OnDec)
	ON_COMMAND(IDC_OCT, &CCovertDlg::OnOct)
	ON_COMMAND(IDC_BIN, &CCovertDlg::OnBin)
END_MESSAGE_MAP()


// CCovertDlg 메시지 처리기입니다.


//void CCovertDlg::OnEnChangeEdit1()
//{
//	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
//	// CDialogEx::OnInitDialog() 함수를 재지정 
//	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
//	// 이 알림 메시지를 보내지 않습니다.
//
//	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}


void CCovertDlg::OnHex()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nResult = _T("16진수");
	UpdateData(FALSE);
}


void CCovertDlg::OnDec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nResult = _T("10진수");
	UpdateData(FALSE);
}


void CCovertDlg::OnOct()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nResult = _T("8진수");
	UpdateData(FALSE);
}


void CCovertDlg::OnBin()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nResult = _T("2진수");
	UpdateData(FALSE);
}
