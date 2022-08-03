#pragma once
#include "afxwin.h"


// CCovertDlg 대화 상자입니다.

class CCovertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCovertDlg)

public:
	CCovertDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCovertDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CCONVERTDIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	/*afx_msg void OnHex();
	afx_msg void OnDec();
	afx_msg void OnOct();
	afx_msg void OnBin();*/
//	CString m_nResult;
	afx_msg void OnClickedBtBack();
	afx_msg void OnClickedBtClear();
	afx_msg void OnClickedBt0();
	afx_msg void OnClickedBt1();
	afx_msg void OnClickedBt2();
	afx_msg void OnClickedBt3();
	afx_msg void OnClickedBt4();
	afx_msg void OnClickedBt5();
	afx_msg void OnClickedBt6();
	afx_msg void OnClickedBt7();
	afx_msg void OnClickedBt8();
	afx_msg void OnClickedBt9();
	afx_msg void OnClickedBta();
	afx_msg void OnClickedBtb();
	afx_msg void OnClickedBtc();
	afx_msg void OnClickedBtd();
	afx_msg void OnClickedBte();
	afx_msg void OnClickedBtf();
	int m_nValue;
	CButton m_ctrlB0;
	CButton m_ctrlB1;
	CButton m_ctrlB2;
	CButton m_ctrlB3;
	CButton m_ctrlB4;
	CButton m_ctrlB5;
	CButton m_ctrlB6;
	CButton m_ctrlB7;
	CButton m_ctrlB8;
	CButton m_ctrlB9;
	CButton m_ctrlBa;
	CButton m_ctrlBb;
	CButton m_ctrlBc;
	CButton m_ctrlBd;
	CButton m_ctrlBe;
	CButton m_ctrlBf;
	CString m_strDisplay;
	int m_nRadix;
	virtual BOOL OnInitDialog();
	void Display();
	bool ValueRange(int value);
	void IntToString(int value, char* buf, int radix);
	afx_msg void OnConvert(UINT value);
};
