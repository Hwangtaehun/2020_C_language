// testDlg2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "testDlg2.h"
#include "afxdialogex.h"


// CTestDlg2 ��ȭ �����Դϴ�.

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


// CTestDlg2 �޽��� ó�����Դϴ�.


void CTestDlg2::OnPlus()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	/*UpdateData(TRUE);
	m_nResult = m_nInput1 + m_nInput2;
	UpdateData(FALSE);*/
}


void CTestDlg2::OnMinus()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	/*UpdateData(TRUE);
	m_nResult = m_nInput1 - m_nInput2;
	UpdateData(FALSE);*/
}


void CTestDlg2::OnMultiply()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	/*UpdateData(TRUE);
	m_nResult = m_nInput1 * m_nInput2;
	UpdateData(FALSE);*/
}


void CTestDlg2::OnDivide()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	/*UpdateData(TRUE);
	m_nResult = m_nInput1 / m_nInput2;
	UpdateData(FALSE);*/
}


void CTestDlg2::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
			MessageBox(_T("0���δ� ���� �� �����."));
		else
			m_nResult = m_nInput1 / m_nInput2;
		break;
	}
	UpdateData(FALSE);
}
