#pragma once


// CTestDlg2 대화 상자입니다.

class CTestDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg2)

public:
	CTestDlg2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTestDlg2();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTESTDLG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nInput1;
	int m_nInput2;
	int m_nResult;
	afx_msg void OnPlus();
	afx_msg void OnMinus();
	afx_msg void OnMultiply();
	afx_msg void OnDivide();
	int m_nRadio;
	afx_msg void OnBnClickedButton2();
};
