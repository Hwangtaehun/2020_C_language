#pragma once


// CHelpDlg 대화 상자

class CHelpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHelpDlg)

public:
	CHelpDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CHelpDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HELPDIG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strHelp;
};
