// calculator1dlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "calculator1dlg.h"
#include "afxdialogex.h"
#include <cmath>


// CCalculator1Dlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCalculator1Dlg, CDialogEx)

CCalculator1Dlg::CCalculator1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculator1Dlg::IDD, pParent)
	, m_nEdit(0)
{
	m_nTot = 0;
	m_cOp = '+';
}

CCalculator1Dlg::~CCalculator1Dlg()
{
}

void CCalculator1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_VIEW, m_nView);
	DDX_Text(pDX, IDC_VIEW, m_nEdit);
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


// CCalculator1Dlg 메시지 처리기입니다.


void CCalculator1Dlg::OnClickedCalcClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nTot = 0;
	m_nEdit = 0;
	m_cOp = '+';
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Calculate();
	m_cOp = '+';
}


void CCalculator1Dlg::OnClickedCalcMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Calculate();
	m_cOp = '-';
}


void CCalculator1Dlg::OnClickedCalcMultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Calculate();
	m_cOp = '*';
}


void CCalculator1Dlg::OnClickedCalcDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다. 
	Calculate();
	m_cOp = '/';
}


void CCalculator1Dlg::OnClickedCalcResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Calculate();
	m_nEdit = m_nTot;
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcOne()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(1);
}


void CCalculator1Dlg::OnClickedCalcTwo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(2);
}


void CCalculator1Dlg::OnClickedCalcThree()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(3);
}


void CCalculator1Dlg::OnClickedCalcFour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(4);
}


void CCalculator1Dlg::OnClickedCalcFive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(5);
}


void CCalculator1Dlg::OnClickedCalcSix()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(6);
}


void CCalculator1Dlg::OnClickedCalcSeven()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(7);
}


void CCalculator1Dlg::OnClickedCalcEight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(8);
}


void CCalculator1Dlg::OnClickedCalcNine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(9);
}


void CCalculator1Dlg::OnClickedCalcZero()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(0);
}



bool CCalculator1Dlg::ValueRange(int value)
{
	if (value <= 2147483647 / 10)
		return true;
	MessageBox(_T("숫자가 너무 큽니다 !!"));
	return false;
}


void CCalculator1Dlg::Calculate()
{
	switch (m_cOp)
	{
	case '+':
		m_nTot += m_nEdit;
		break;
	case '-':
		m_nTot -= m_nEdit;
		break;
	case '*':
		m_nTot *= m_nEdit;
		break;
	case '/':
		if (m_nEdit == 0)
			MessageBox(_T("0으로는 나눌 수 없어요."));
		else
			m_nTot /= m_nEdit;
		break;
	}
	m_nEdit = 0;
}


void CCalculator1Dlg::Number(int n)
{
	// TODO: 여기에 구현 코드 추가.
	if (ValueRange(m_nEdit))
		m_nEdit = m_nEdit * 10 + n;
	UpdateData(FALSE);
}
