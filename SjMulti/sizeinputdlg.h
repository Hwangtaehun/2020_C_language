#pragma once
#include "afxcmn.h"


// CSizeInPutDlg ��ȭ �����Դϴ�.

class CSizeInPutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSizeInPutDlg)

public:
	CSizeInPutDlg(CWnd* pParent = NULL, int nStart = 10, int nEnd = 30);   // ǥ�� �������Դϴ�.
	virtual ~CSizeInPutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SIZEINPUTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nStart;
	int m_nEnd;
	CSpinButtonCtrl m_ctrlSpin;
	int m_nEdit;
	CString m_strTitle;
	virtual BOOL OnInitDialog();
};
