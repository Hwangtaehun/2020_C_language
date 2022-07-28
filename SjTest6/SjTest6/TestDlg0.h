#pragma once


// CTestDlg0 대화 상자입니다.

class CTestDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg0)

public:
	CTestDlg0(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTestDlg0();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
