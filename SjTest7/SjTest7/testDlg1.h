#pragma once


// CTestDlg1 ��ȭ �����Դϴ�.

class CTestDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg1)

public:
	CTestDlg1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTestDlg1();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CTESTDLG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	int m_nAge;
	int m_nScore;
	afx_msg void OnClickedCalcBt();
};
