#pragma once


// CTestDlg1 대화 상자입니다.

class CTestDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg1)

public:
	CTestDlg1(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTestDlg1();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTESTDLG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	int m_nAge;
	int m_nScore;
	afx_msg void OnClickedCalcBt();
};
