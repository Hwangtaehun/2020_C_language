
// SjOdbc1.h : SjOdbc1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjOdbc1App:
// �� Ŭ������ ������ ���ؼ��� SjOdbc1.cpp�� �����Ͻʽÿ�.
//

class CSjOdbc1App : public CWinApp
{
public:
	CSjOdbc1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjOdbc1App theApp;
