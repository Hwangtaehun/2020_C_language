
// SjSplitter.h : SjSplitter ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjSplitterApp:
// �� Ŭ������ ������ ���ؼ��� SjSplitter.cpp�� �����Ͻʽÿ�.
//

class CSjSplitterApp : public CWinApp
{
public:
	CSjSplitterApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjSplitterApp theApp;
