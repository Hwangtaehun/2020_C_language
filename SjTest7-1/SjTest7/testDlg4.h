#pragma once


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
};
