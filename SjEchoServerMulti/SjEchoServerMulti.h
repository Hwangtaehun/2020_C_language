
// SjEchoServerMulti.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSjEchoServerMultiApp:
// �� Ŭ������ ������ ���ؼ��� SjEchoServerMulti.cpp�� �����Ͻʽÿ�.
//

class CSjEchoServerMultiApp : public CWinApp
{
public:
	CSjEchoServerMultiApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSjEchoServerMultiApp theApp;