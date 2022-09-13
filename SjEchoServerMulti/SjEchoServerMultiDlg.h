
// SjEchoServerMultiDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "MyServerSocket.h"
#include "MySocket.h"
#define MAX_USER 5
#define DATA_SIZE 100

// CSjEchoServerMultiDlg 대화 상자
class CSjEchoServerMultiDlg : public CDialogEx
{
// 생성입니다.
public:
	CSjEchoServerMultiDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SJECHOSERVERMULTI_DIALOG };

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
	CButton m_ctrlStartBt;
	CButton m_ctrlStopBt;
	int m_nPortNo;
	CString m_strMsg;
	CEdit m_ctrlMsg;
	CMyServerSocket m_Server;
	CMySocket m_Client[MAX_USER];
	int m_nCnt;
	afx_msg LRESULT OnAcceptMsg(WPARAM wParam, LPARAM IParam);
	afx_msg void OnClickedStartBt();
	afx_msg void OnClickedStopBt();
	afx_msg LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
};
