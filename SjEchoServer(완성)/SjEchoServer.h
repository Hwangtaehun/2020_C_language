
// SjEchoServer.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSjEchoServerApp:
// �� Ŭ������ ������ ���ؼ��� SjEchoServer.cpp�� �����Ͻʽÿ�.
//

class CSjEchoServerApp : public CWinApp
{
public:
	CSjEchoServerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSjEchoServerApp theApp;