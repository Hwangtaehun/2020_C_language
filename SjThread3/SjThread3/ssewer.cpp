// ssewer.cpp: 구현 파일
//

#include "pch.h"
#include "SjThread3.h"
#include "ssewer.h"


// ssewer

IMPLEMENT_DYNCREATE(ssewer, CWinThread)

ssewer::ssewer()
{
}

ssewer::~ssewer()
{
}

BOOL ssewer::InitInstance()
{
	// TODO:  여기에서 각 스레드에 대한 초기화를 수행합니다.
	return TRUE;
}

int ssewer::ExitInstance()
{
	// TODO:  여기에서 각 스레드에 대한 정리를 수행합니다.
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(ssewer, CWinThread)
END_MESSAGE_MAP()


// ssewer 메시지 처리기
