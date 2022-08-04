// EditNumber.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SjTest7.h"
#include "EditNumber.h"


// CEditNumber

IMPLEMENT_DYNAMIC(CEditNumber, CEdit)

CEditNumber::CEditNumber()
{

}

CEditNumber::~CEditNumber()
{
}


BEGIN_MESSAGE_MAP(CEditNumber, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CEditNumber 메시지 처리기입니다.

void CEditNumber::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if ((nChar >= '0' && nChar <= '9') || nChar == VK_BACK)
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	else
		MessageBeep(1);
}
