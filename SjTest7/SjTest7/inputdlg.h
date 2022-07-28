#pragma once


// inputdlg 대화 상자

class inputdlg : public CDialogEx
{
	DECLARE_DYNAMIC(inputdlg)

public:
	inputdlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~inputdlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CINPUTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
