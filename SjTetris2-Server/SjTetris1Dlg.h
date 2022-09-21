
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
#define HOST_X 10
#define HOST_Y 10
#define GUEST_X 340
#define GUEST_Y 10
#define HOST_XSIZE 320
#define HOST_YSIZE 640
#define GUEST_XSIZE 140
#define GUEST_YSIZE 280
#define STATE_INIT 0		
#define STATE_WAIT 1		
#define STATE_CONNECT 2		
#define STATE_GAME_START 3	
#define STATE_GAME_DIE 4
#define SERVER_MODE 0
#define CLIENT_MODE 1
#define SINGLE_MODE 2
#define BUFFER_SIZE  200
#define SEND_SIZE sizeof(struct SEND_DATA)
#define MSG_CNT 10

struct SEND_DATA
{
	int nMyNo;
	int nScore;
	char Buf[BUFFER_SIZE];
	char nFlag;
};

struct GUEST_DATA
{
	CString strName;
	int nScore;
	//void *pClient;
	CSjClientSocket* pClient;
	char cFlag;
};

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
	CBitmap m_bmBack2;
	CBitmap m_bmNumber;
	CDC m_NumberDC;
	CDC m_BackDC;
	CDC m_BlockDC;
	CDC m_BackDC2;
	CDC *m_pDC;
	char m_Table[USER_CNT][ROW_CNT][COL_CNT];
	CRect m_nextRect;
	CRect m_mainRect;
	//CRect m_mainRect2;
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
	int m_nNextPattern;
	void NextBlock(bool bFlag);
	void DrawScr2();
//	char m_Table2[ROW_CNT][COL_CNT];
	void DrawScr3(void *pt, int nClientNo, bool bFlag);
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
	afx_msg LRESULT OnAcceptMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnCloseMsg(WPARAM wParam, LPARAM IParam);
	void DisplayMsg(CString strMsg);
	void InitGuestData();
	CButton m_ctrlRadioServer;
	CButton m_ctrlRadioSingle;
	CButton m_ctrlRadioClient;
	void DisplayAllGuest();
	SEND_DATA m_sendData;
	int m_nGameMode;
	afx_msg void OnGameMode(UINT nID);
	int m_nMyNo;
	int m_nConnectCnt;
	char m_Buf[BUFFER_SIZE];
	int m_nScore;
	int m_nStage;
	int m_nTime;
	//BOOL m_bStart;
	GUEST_DATA m_Guest[USER_CNT];
};
