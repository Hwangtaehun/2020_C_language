
// SejongMine.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSejongMineApp:
// �� Ŭ������ ������ ���ؼ��� SejongMine.cpp�� �����Ͻʽÿ�.
//

class CSejongMineApp : public CWinApp
{
public:
	CSejongMineApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSejongMineApp theApp;