#pragma once
#include "afxwin.h"


// CTestDlg4 ��ȭ �����Դϴ�.

class CTestDlg4 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg4)

public:
	CTestDlg4(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTestDlg4();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CTESTDLG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
