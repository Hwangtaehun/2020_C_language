#pragma once


// CTestDlg2 ��ȭ �����Դϴ�.

class CTestDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg2)

public:
	CTestDlg2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTestDlg2();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CTESTDLG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
