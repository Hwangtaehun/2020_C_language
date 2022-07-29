// testDlg2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "testDlg2.h"
#include "afxdialogex.h"


// CTestDlg2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTestDlg2, CDialogEx)

CTestDlg2::CTestDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg2::IDD, pParent)
	, m_nInput1(0)
	, m_nInput2(0)
	, m_nResult(0)
	, m_nRadio(0)
{

}

CTestDlg2::~CTestDlg2()
{
}

void CTestDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDM_INPUT1, m_nInput1);
	DDX_Text(pDX, IDC_INPUT2, m_nInput2);
	DDX_Text(pDX, IDC_RESULT, m_nResult);
	//  DDX_Radio(pDX, IDC_MINUS, m_nRadio);
	DDX_Radio(pDX, IDC_PLUS, m_nRadio);
}


BEGIN_MESSAGE_MAP(CTestDlg2, CDialogEx)
	ON_COMMAND(IDC_PLUS, &CTestDlg2::OnPlus)
	ON_COMMAND(IDC_MINUS, &CTestDlg2::OnMinus)
	ON_COMMAND(IDC_MULTIPLY, &CTestDlg2::OnMultiply)
	ON_COMMAND(IDC_DIVIDE, &CTestDlg2::OnDivide)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestDlg2::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTestDlg2 메시지 처리기입니다.


void CTestDlg2::OnPlus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	/*UpdateData(TRUE);
	m_nResult = m_nInput1 + m_nInput2;
	UpdateData(FALSE);*/
}


void CTestDlg2::OnMinus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	/*UpdateData(TRUE);
	m_nResult = m_nInput1 - m_nInput2;
	UpdateData(FALSE);*/
}


void CTestDlg2::OnMultiply()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	/*UpdateData(TRUE);
	m_nResult = m_nInput1 * m_nInput2;
	UpdateData(FALSE);*/
}


void CTestDlg2::OnDivide()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	/*UpdateData(TRUE);
	m_nResult = m_nInput1 / m_nInput2;
	UpdateData(FALSE);*/
}


void CTestDlg2::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	switch (m_nRadio)
	{
	case 0:
		m_nResult = m_nInput1 + m_nInput2;
		break;
	case 1:
		m_nResult = m_nInput1 - m_nInput2;
		break;
	case 2:
		m_nResult = m_nInput1 * m_nInput2;
		break;
	case 3:
		if (m_nInput2 == 0)
			MessageBox(_T("0으로는 나눌 수 없어요."));
		else
			m_nResult = m_nInput1 / m_nInput2;
		break;
	}
	UpdateData(FALSE);
}
