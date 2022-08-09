#pragma once


// CModelessDlg 대화 상자

class CModelessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModelessDlg)

public:
	CModelessDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CModelessDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODELESSDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExitmodeless();
	virtual void PostNcDestroy();
	enum{IDD = IDD_MODELESSDLG};
	virtual BOOL Create(CWnd* pParentWnd = NULL);
};
