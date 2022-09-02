
// LatinSquareDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#define NUM_CNT 9
#define BMP_SIZE 48
#define DISP_SIZE 52
#define START_X 10
#define START_Y 10

// CLatinSquareDlg ��ȭ ����
class CLatinSquareDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CLatinSquareDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LATINSQUARE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nExamNo;
	int m_nHintCnt;
	CString m_strTime;
	CButton m_ctrlStartBt;
	CButton m_ctrlStopBt;
	CButton m_ctrlExamBt;
	CButton m_ctrlHintBt;
	CButton m_ctrlCheckBt;
	CSpinButtonCtrl m_ctrlSpin;
	afx_msg void OnClickedButtonExam();
	afx_msg void OnClickedButtonCheck();
	afx_msg void OnClickedButtonHelp();
	afx_msg void OnClickedButtonHint();
	afx_msg void OnClickedButtonGamestart();
	afx_msg void OnClickedButtonGamestop();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDC* m_pDC;
	CDC m_NumberDC;
	CBitmap m_bmNumber;
	char m_cTable[NUM_CNT][NUM_CNT];
	char m_aTable[NUM_CNT][NUM_CNT];
	char m_bTable[NUM_CNT][NUM_CNT];
	CRect m_WndRect;
	CRect m_NumRect;
	CPoint m_Point;
	int m_nX;
	int m_nY;
	int m_Time;
	int m_munCnt;
	bool m_bGame;
	void InitGame();
	void AllViews();
	void DrawLine();
	void ViewPic(int x, int y);
	void DrawBox(int x, int y);
	int IsNumber(int n);
	bool IsDuplicate(int x, int y, int num);
	void DrawX(int x, int y);
	CButton m_ctrlSaveBt;
	void WriteFile();
};
