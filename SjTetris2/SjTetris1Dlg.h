
// SjTetris1Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#define COL_CNT 10
#define ROW_CNT 20
#define START_X 10
#define START_Y 10
#define BLOCK_SIZE 32

// CSjTetris1Dlg ��ȭ ����
class CSjTetris1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSjTetris1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SJTETRIS1_DIALOG };

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
	CBitmap m_bmBlock;
	CBitmap m_bmBack;
	CDC m_BackDC;
	CDC m_BlockDC;
	CDC *m_pDC;
	char m_Table[6][ROW_CNT][COL_CNT];
	CRect m_nextRect;
	CRect m_mainRect;
	CRect m_mainRect2;
	BOOL m_bStart;
	int m_nPattern;
	int m_nBitType;
	int m_nRot;
	int m_nX;
	int m_nY;
	CButton m_ctrlStartBt;
	CButton m_ctrlStopBt;
	void DrawScr();
	void InitialGame();
	void DrawBlock(bool bFlag);
	BOOL BlockDown();
	BOOL IsAround(int nX, int nY);
	void SetTable();
	void RolateBlock(bool bFlag);
	void MoveDown();
	void MoveRight();
	void MoveLeft();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_nScore;
	int m_nNextPattern;
	void NextBlock(bool bFlag);
	void DrawScr2();
	char m_Table2[ROW_CNT][COL_CNT];
	void DrawScr3(int i, int x, int y);
};
