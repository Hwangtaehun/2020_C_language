#pragma once


// converdlg 대화 상자

class converdlg : public CDialogEx
{
	DECLARE_DYNAMIC(converdlg)

public:
	converdlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~converdlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CCONVERTDIG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
