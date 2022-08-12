#pragma once
#include "afxcmn.h"


// CSizeInPutDlg 대화 상자입니다.

class CSizeInPutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSizeInPutDlg)

public:
	CSizeInPutDlg(CWnd* pParent = NULL, int nStart = 10, int nEnd = 30);   // 표준 생성자입니다.
	virtual ~CSizeInPutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SIZEINPUTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nStart;
	int m_nEnd;
	CSpinButtonCtrl m_ctrlSpin;
	int m_nEdit;
	CString m_strTitle;
	virtual BOOL OnInitDialog();
};
