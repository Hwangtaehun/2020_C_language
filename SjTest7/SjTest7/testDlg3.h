#pragma once
#include "afxwin.h"


// CTestDlg3 ��ȭ �����Դϴ�.

class CTestDlg3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg3)

public:
	CTestDlg3(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTestDlg3();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CTESTDLG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ctrlEdit1;
	CEdit m_ctrlEdit2;
	BOOL m_bShow;
	BOOL m_bEnable;
	afx_msg void OnClickedCheckUse();
	afx_msg void OnClickedCheckShow();
};
