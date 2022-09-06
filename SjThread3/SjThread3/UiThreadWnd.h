#pragma once


// CUiThreadWnd 프레임

class CUiThreadWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CUiThreadWnd)
protected:
	DECLARE_MESSAGE_MAP()
public:
	CUiThreadWnd();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CUiThreadWnd();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


