#pragma once


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
};
