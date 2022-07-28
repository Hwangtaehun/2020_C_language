#pragma once


// calculator2dlg 대화 상자

class calculator2dlg : public CDialogEx
{
	DECLARE_DYNAMIC(calculator2dlg)

public:
	calculator2dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~calculator2dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CCALCULATOR2DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
