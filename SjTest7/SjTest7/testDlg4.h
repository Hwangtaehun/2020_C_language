#pragma once
#include "afxwin.h"


// CTestDlg4 대화 상자입니다.

class CTestDlg4 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg4)

public:
	CTestDlg4(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTestDlg4();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTESTDLG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_ctrlList;
	CString m_strList;
	CComboBox m_ctrlCombo;
	CString m_strSelected;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList1();
	afx_msg void OnCbnSelchangeCombo1();
};
