#pragma once


// testDlg4 대화 상자

class testDlg4 : public CDialogEx
{
	DECLARE_DYNAMIC(testDlg4)

public:
	testDlg4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~testDlg4();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CTESTDLG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
