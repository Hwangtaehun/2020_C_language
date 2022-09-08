
// SjEchoClientDlg.h : ��� ����
//

#pragma once
#include "MySocket.h"

// CSjEchoClientDlg ��ȭ ����
class CSjEchoClientDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSjEchoClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SJECHOCLIENT_DIALOG };

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
