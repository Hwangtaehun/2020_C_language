#pragma once


// CInputDlg ��ȭ �����Դϴ�.

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInputDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CINPUTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
