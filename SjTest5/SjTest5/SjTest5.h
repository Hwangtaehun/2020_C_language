
// SjTest5.h : SjTest5 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSjTest5App:
// �� Ŭ������ ������ ���ؼ��� SjTest5.cpp�� �����Ͻʽÿ�.
//

class CSjTest5App : public CWinApp
{
public:
	CSjTest5App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSjTest5App theApp;
