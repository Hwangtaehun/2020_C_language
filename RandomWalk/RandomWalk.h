
// RandomWalk.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CRandomWalkApp:
// �� Ŭ������ ������ ���ؼ��� RandomWalk.cpp�� �����Ͻʽÿ�.
//

class CRandomWalkApp : public CWinApp
{
public:
	CRandomWalkApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CRandomWalkApp theApp;