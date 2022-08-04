#pragma once


// CCalculator1Dlg 대화 상자입니다.

class CCalculator1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCalculator1Dlg)

public:
	CCalculator1Dlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCalculator1Dlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CCALCULATOR1DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnClickedCalcClear();
	afx_msg void OnClickedCalcPlus();
	afx_msg void OnClickedCalcMinus();
	afx_msg void OnClickedCalcMultiply();
	afx_msg void OnClickedCalcDivide();
	afx_msg void OnClickedCalcResult();
	afx_msg void OnClickedCalcOne();
	afx_msg void OnClickedCalcTwo();
	afx_msg void OnClickedCalcThree();
	afx_msg void OnClickedCalcFour();
	afx_msg void OnClickedCalcFive();
	afx_msg void OnClickedCalcSix();
	afx_msg void OnClickedCalcSeven();
	afx_msg void OnClickedCalcEight();
	afx_msg void OnClickedCalcNine();
	afx_msg void OnClickedCalcZero();
	int m_nTot;
	char m_cOp;
	int m_nEdit;
	bool ValueRange(int value);
	void Calculate();
	void Number(int n);
};
