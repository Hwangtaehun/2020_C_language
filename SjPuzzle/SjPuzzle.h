
// SjPuzzle.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSjPuzzleApp:
// �� Ŭ������ ������ ���ؼ��� SjPuzzle.cpp�� �����Ͻʽÿ�.
//

class CSjPuzzleApp : public CWinApp
{
public:
	CSjPuzzleApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSjPuzzleApp theApp;