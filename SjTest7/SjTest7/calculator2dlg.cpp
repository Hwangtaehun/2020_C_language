// calculator2dlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "calculator2dlg.h"
#include "afxdialogex.h"


// CCalculator2Dlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCalculator2Dlg, CDialogEx)

CCalculator2Dlg::CCalculator2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculator2Dlg::IDD, pParent)
	, m_strInFix(_T(""))
	, m_strPostFix(_T(""))
	, m_nResult(0)
{

	OpTop = 0;
	PostTop = 0;
	CompTop = 0;
}

CCalculator2Dlg::~CCalculator2Dlg()
{
}

void CCalculator2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INFIX, m_strInFix);
	DDX_Text(pDX, IDC_POSTFIX, m_strPostFix);
	DDX_Text(pDX, IDC_RESULT, m_nResult);
}


BEGIN_MESSAGE_MAP(CCalculator2Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BT0, &CCalculator2Dlg::OnClickedBt0)
	ON_BN_CLICKED(IDC_BT1, &CCalculator2Dlg::OnClickedBt1)
	ON_BN_CLICKED(IDC_BT2, &CCalculator2Dlg::OnClickedBt2)
	ON_BN_CLICKED(IDC_BT3, &CCalculator2Dlg::OnClickedBt3)
	ON_BN_CLICKED(IDC_BT4, &CCalculator2Dlg::OnClickedBt4)
	ON_BN_CLICKED(IDC_BT5, &CCalculator2Dlg::OnClickedBt5)
	ON_BN_CLICKED(IDC_BT6, &CCalculator2Dlg::OnClickedBt6)
	ON_BN_CLICKED(IDC_BT7, &CCalculator2Dlg::OnClickedBt7)
	ON_BN_CLICKED(IDC_BT8, &CCalculator2Dlg::OnClickedBt8)
	ON_BN_CLICKED(IDC_BT9, &CCalculator2Dlg::OnClickedBt9)
	ON_BN_CLICKED(IDC_COMPUTE, &CCalculator2Dlg::OnClickedCompute)
	ON_BN_CLICKED(IDC_BT_SQUARE, &CCalculator2Dlg::OnClickedBtSquare)
	ON_BN_CLICKED(IDC_BT_PLUS, &CCalculator2Dlg::OnClickedBtPlus)
	ON_BN_CLICKED(IDC_BT_MINUS, &CCalculator2Dlg::OnClickedBtMinus)
	ON_BN_CLICKED(IDC_BT_MULTIPLY, &CCalculator2Dlg::OnClickedBtMultiply)
	ON_BN_CLICKED(IDC_BT_DIVIDE, &CCalculator2Dlg::OnClickedBtDivide)
END_MESSAGE_MAP()


// CCalculator2Dlg �޽��� ó�����Դϴ�.


void CCalculator2Dlg::OnClickedBt0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBt1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBt2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBt3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBt4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBt5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBt6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBt7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBt8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBt9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedCompute()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBtSquare()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBtPlus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBtMinus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBtMultiply()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalculator2Dlg::OnClickedBtDivide()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
