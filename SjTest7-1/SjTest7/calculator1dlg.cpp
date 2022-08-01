// calculator1dlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "calculator1dlg.h"
#include "afxdialogex.h"
#include <cmath>


// CCalculator1Dlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCalculator1Dlg, CDialogEx)

CCalculator1Dlg::CCalculator1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculator1Dlg::IDD, pParent)
	, m_nView(_T(""))
{

	m_nInput1 = 0;
	m_nInput2 = 0;
	m_nSign = 0;
	m_nResult = 0;
	cnt = 0;
}

CCalculator1Dlg::~CCalculator1Dlg()
{
}

void CCalculator1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_VIEW, m_nView);
}


BEGIN_MESSAGE_MAP(CCalculator1Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_CALC_CLEAR, &CCalculator1Dlg::OnClickedCalcClear)
	ON_BN_CLICKED(IDC_CALC_PLUS, &CCalculator1Dlg::OnClickedCalcPlus)
	ON_BN_CLICKED(IDC_CALC_MINUS, &CCalculator1Dlg::OnClickedCalcMinus)
	ON_BN_CLICKED(IDC_CALC_MULTIPLY, &CCalculator1Dlg::OnClickedCalcMultiply)
	ON_BN_CLICKED(IDC_CALC_DIVIDE, &CCalculator1Dlg::OnClickedCalcDivide)
	ON_BN_CLICKED(IDC_CALC_RESULT, &CCalculator1Dlg::OnClickedCalcResult)
	ON_BN_CLICKED(IDC_CALC_ONE, &CCalculator1Dlg::OnClickedCalcOne)
	ON_BN_CLICKED(IDC_CALC_TWO, &CCalculator1Dlg::OnClickedCalcTwo)
	ON_BN_CLICKED(IDC_CALC_THREE, &CCalculator1Dlg::OnClickedCalcThree)
	ON_BN_CLICKED(IDC_CALC_FOUR, &CCalculator1Dlg::OnClickedCalcFour)
	ON_BN_CLICKED(IDC_CALC_FIVE, &CCalculator1Dlg::OnClickedCalcFive)
	ON_BN_CLICKED(IDC_CALC_SIX, &CCalculator1Dlg::OnClickedCalcSix)
	ON_BN_CLICKED(IDC_CALC_SEVEN, &CCalculator1Dlg::OnClickedCalcSeven)
	ON_BN_CLICKED(IDC_CALC_EIGHT, &CCalculator1Dlg::OnClickedCalcEight)
	ON_BN_CLICKED(IDC_CALC_NINE, &CCalculator1Dlg::OnClickedCalcNine)
	ON_BN_CLICKED(IDC_CALC_ZERO, &CCalculator1Dlg::OnClickedCalcZero)
END_MESSAGE_MAP()


// CCalculator1Dlg �޽��� ó�����Դϴ�.


void CCalculator1Dlg::OnClickedCalcClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nInput1 = 0;
	m_nInput2 = 0;
	m_nSign = 0;
	m_nView =_T("");
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcPlus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nSign = 0;
	m_nView = _T("+");
	Total(m_nInput1);
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcMinus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nSign = 1;
	m_nView = _T("-");
	Total(m_nInput1);
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcMultiply()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nSign = 2;
	m_nView = _T("*");
	Total(m_nInput1);
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcDivide()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�. 
	UpdateData(TRUE);
	m_nSign = 3;
	m_nView = _T("/");
	Total(m_nInput1);
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcResult()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	Total(m_nInput2);
	switch (m_nSign)
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
		m_nResult = m_nInput1 / m_nInput2;
		break;
	}
	m_nView.Format(_T("%d"), m_nResult);
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcOne()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(1);
}


void CCalculator1Dlg::OnClickedCalcTwo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(2);
}


void CCalculator1Dlg::OnClickedCalcThree()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(3);
}


void CCalculator1Dlg::OnClickedCalcFour()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(4);
}


void CCalculator1Dlg::OnClickedCalcFive()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(5);
}


void CCalculator1Dlg::OnClickedCalcSix()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(6);
}


void CCalculator1Dlg::OnClickedCalcSeven()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(7);
}


void CCalculator1Dlg::OnClickedCalcEight()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(8);
}


void CCalculator1Dlg::OnClickedCalcNine()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(9);
}


void CCalculator1Dlg::OnClickedCalcZero()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PEN(0);
}


void CCalculator1Dlg::PEN(int a)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	UpdateData(TRUE);
	if (cnt>9)
	{
		m_nView = _T("���ڸ� �ʰ��߽��ϴ�.");
	}
	else
	{
		m_nSize[cnt] = a;
		m_nView.Format(_T("%d"), a);
		cnt++;
	}
	UpdateData(FALSE);
}


int CCalculator1Dlg::Total(int n)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int i, tmep;
	for (i = 0; i < cnt / 2; i++)
	{
		tmep = m_nSize[i];
		m_nSize[i] = m_nSize[cnt - i];
		m_nSize[cnt - i] = m_nSize[i];
	}
	n = m_nSize[0];
	n += m_nSize[1] * 10;
	n += m_nSize[2] * 100;
	n += m_nSize[3] * 1000;
	n += m_nSize[4] * 10000;
	n += m_nSize[5] * 100000;
	n += m_nSize[6] * 1000000;
	n += m_nSize[7] * 10000000;
	n += m_nSize[8] * 100000000;
	n += m_nSize[9] * 1000000000;
	return n;
}
