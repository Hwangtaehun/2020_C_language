
// SjPuzzleDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#define PIC_SIZE 500
#define HINT_SIZE 300
#define START_X 7
#define START_Y 7
#define WINDOW_XSIZE 860
#define WINDOW_YSIZE 560

// CSjPuzzleDlg ��ȭ ����
class CSjPuzzleDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSjPuzzleDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SJPUZZLE_DIALOG };

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
	CDC *m_pDC;
	CDC m_mainDC;
	CDC m_hintDC;
	CBitmap m_bitMain;
	CBitmap m_bitHint;
	int m_aMap[9][9];
	BOOL m_bGameClear;
	BOOL m_bGameStart;
	BOOL m_bHint;
	CRect m_mainRect;
	CRect m_hintRect;
	int m_nXSize;
	int m_nYSize;
	int m_colCnt;
	int m_rowCnt;
	int m_moveCnt;
	int m_nTime;
	CString m_strCorect;
	BOOL m_bNumber;
	CButton m_ctrlStartBt;
	CButton m_ctrlStopBt;
	afx_msg void OnClickedStartButton();
	afx_msg void OnClickedStopButton();
	afx_msg void OnClickedEndButton();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedShowNumber();
	void InitialData();
	void DrawRectAll();
	void DrawRect(int nX, int nY);
	void DisplayAll();
	void DrawPicture(int nX, int nY, int nPictureNo);
	BOOL CorrectCount();
	void DisplayNumber();
	BOOL EmptyPosition(int& nX, int& nY);
	void MovePicture(int nX, int nY, int eX, int eY, int nTime);
	void DIsplayOriginal();
	void PreView();
	void ClearGame();
	void MixedPicture();
};
