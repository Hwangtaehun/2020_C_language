#pragma once


// CModalDlg 대화 상자

class CModalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModalDlg)

public:
	CModalDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CModalDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODALDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExitdlg();
};
