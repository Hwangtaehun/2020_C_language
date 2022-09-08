
// SjEchoClientDlg.h : 헤더 파일
//

#pragma once
#include "MySocket.h"

// CSjEchoClientDlg 대화 상자
class CSjEchoClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CSjEchoClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SJECHOCLIENT_DIALOG };

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
	CButton m_ctrlConnectBt;
	CButton m_ctrlDisConnectBt;
	CButton m_ctrlSendBt;
	CString m_strIpAddress;
	CEdit m_ctrlIpAddress;
	int m_nPortNo;
	CString m_strSendData;
	CEdit m_ctrlSendData;
	CString m_strReceiveData;
	CEdit m_ctrlReceiveData;
	afx_msg void OnClickedConnectBt();
//	CSocket m_Socket;
	afx_msg void OnClickedDisconnectBt();
	afx_msg void OnClickedSendBt();
	CMySocket m_Socket;
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg LRESULT OnReceiveMsg(WPARAM wParam, LPARAM IParam);
	bool m_bConnect;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
