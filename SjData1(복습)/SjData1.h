
// SjData1.h : SjData1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjData1App:
// �� Ŭ������ ������ ���ؼ��� SjData1.cpp�� �����Ͻʽÿ�.
//

class CSjData1App : public CWinAppEx
{
public:
	CSjData1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjData1App theApp;
