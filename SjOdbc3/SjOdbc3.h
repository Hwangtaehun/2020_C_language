
// SjOdbc3.h : SjOdbc3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjOdbc3App:
// �� Ŭ������ ������ ���ؼ��� SjOdbc3.cpp�� �����Ͻʽÿ�.
//

class CSjOdbc3App : public CWinApp
{
public:
	CSjOdbc3App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjOdbc3App theApp;
