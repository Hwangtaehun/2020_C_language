
// SjTetris1Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "SjClientSocket.h"
#include "SjServerSocket.h"
#include "afxcoll.h"

#define COL_CNT 10
#define ROW_CNT 20
#define START_X 10
#define START_Y 10
#define BLOCK_SIZE 32
#define USER_CNT 6
#define STATE_INIT 0
#define STATE_WAIT 1
#define STATE_CONNECT 2
#define STATE_GAME_START 3
#define STATE_GAME_DIE 4
#define DATA_SIZE 201

// CSjTetris1Dlg 대화 상자
class CSjTetris1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CSjTetris1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SJTETRIS1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
	char m_Table[USER_CNT][ROW_CNT][COL_CNT];
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
	int m_nScore2;
	int m_nScore3;
	int m_nScore4;
	int m_nScore5;
	int m_nScore6;
	CSjServerSocket m_Server;
	CSjClientSocket m_Client;
	CButton m_ctrlConnectBt;
	CButton m_ctrlDisConnectBt;
	CButton m_ctrlSendBt;
	CString m_strName;
	int m_nPortNo;
	CString m_strSendData;
	CEdit m_ctrlSendData;
	CString m_strIpAddress;
	CEdit m_ctrlIpAddress;
	int m_nState;
	CString m_arrMsg[10];
	afx_msg void OnClickedConnectBt();
	afx_msg void OnClickedDisconnectBt();
	afx_msg void OnClickedSendBt();
	LRESULT OnAcceptMsg(WPARAM wParam, LPARAM IParam);
	LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
	LRESULT OnCloseMsg(WPARAM wParam, LPARAM IParam);
	void DisplayMsg(CString strMsg);
	void InitGuestData();
};
