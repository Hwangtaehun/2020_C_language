#pragma once


// CTestDlg0 ��ȭ �����Դϴ�.

class CTestDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg0)

public:
	CTestDlg0(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTestDlg0();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
