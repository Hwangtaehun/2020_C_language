// calculator1dlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "calculator1dlg.h"
#include "afxdialogex.h"


// CCalculator1Dlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCalculator1Dlg, CDialogEx)

CCalculator1Dlg::CCalculator1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculator1Dlg::IDD, pParent)
	, m_nView(_T(""))
{

	m_nInput1 = 0;
	m_nInput2 = 0;
	m_nSign = 0;
	m_nResult = 0;
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


// CCalculator1Dlg 메시지 처리기입니다.


void CCalculator1Dlg::OnClickedCalcClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nInput1 = 0;
	m_nInput2 = 0;
	m_nSign = 0;
	m_nView =_T("");
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nSign = 0;
	m_nView = _T("+");
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nSign = 1;
	m_nView = _T("-");
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcMultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nSign = 2;
	m_nView = _T("*");
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다. 
	UpdateData(TRUE);
	m_nSign = 3;
	m_nView = _T("/");
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
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
	m_nView = _T("%d", m_nResult);
	UpdateData(FALSE);
}


void CCalculator1Dlg::OnClickedCalcOne()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculator1Dlg::OnClickedCalcTwo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculator1Dlg::OnClickedCalcThree()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculator1Dlg::OnClickedCalcFour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculator1Dlg::OnClickedCalcFive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculator1Dlg::OnClickedCalcSix()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculator1Dlg::OnClickedCalcSeven()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculator1Dlg::OnClickedCalcEight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculator1Dlg::OnClickedCalcNine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalculator1Dlg::OnClickedCalcZero()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
