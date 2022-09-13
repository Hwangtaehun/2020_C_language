
// SjEchoServerMulti2Dlg.h : 헤더 파일
//

#pragma once
#include "SjClientSocket.h"
#include "SjServerSocket.h"
#include "afxwin.h"

// CSjEchoServerMulti2Dlg 대화 상자
class CSjEchoServerMulti2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CSjEchoServerMulti2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SJECHOSERVERMULTI2_DIALOG };

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
	CSjServerSocket m_Server;
	CSjClientSocket *m_pClient;
	int m_nCnt;
	afx_msg void OnClickedStartBt();
	afx_msg void OnClickedStopBt();
	afx_msg LRESULT OnAcceptMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnCloseMsg(WPARAM wParam, LPARAM IParam);
};
