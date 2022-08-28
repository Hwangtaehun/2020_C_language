#pragma once


// CustomDlg 대화 상자

class CustomDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CustomDlg)

public:
	CustomDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CustomDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CUSTOMDIG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nMine;
	int m_nHeight;
	int m_nWidth;
};
