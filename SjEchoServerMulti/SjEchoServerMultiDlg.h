
// SjEchoServerMultiDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "MyServerSocket.h"
#include "MySocket.h"
#define MAX_USER 5
#define DATA_SIZE 100

// CSjEchoServerMultiDlg ��ȭ ����
class CSjEchoServerMultiDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSjEchoServerMultiDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SJECHOSERVERMULTI_DIALOG };

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
