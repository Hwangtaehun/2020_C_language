#pragma once
#include "afxwin.h"


// CTestDlg3 대화 상자입니다.

class CTestDlg3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg3)

public:
	CTestDlg3(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTestDlg3();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTESTDLG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ctrlEdit1;
	CEdit m_ctrlEdit2;
	BOOL m_bShow;
	BOOL m_bEnable;
	afx_msg void OnClickedCheckUse();
	afx_msg void OnClickedCheckShow();
};
