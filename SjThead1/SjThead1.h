
// SjThead1.h : SjThead1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjThead1App:
// �� Ŭ������ ������ ���ؼ��� SjThead1.cpp�� �����Ͻʽÿ�.
//

class CSjThead1App : public CWinAppEx
{
public:
	CSjThead1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjThead1App theApp;
