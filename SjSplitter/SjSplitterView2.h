#pragma once


// CSjSplitterView2 뷰입니다.

class CSjSplitterView2 : public CView
{
	DECLARE_DYNCREATE(CSjSplitterView2)

protected:
	CSjSplitterView2();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CSjSplitterView2();

public:
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

public:
	CSjSplitterDoc* GetDocument() const;
	int m_nSize;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void DrawEllipse(CDC * pDC, CPoint point);
	afx_msg void OnOne();
	afx_msg void OnTwo();
	afx_msg void OnThree();
};

#ifndef _DEBUG  // SjSplitterView.cpp의 디버그 버전
inline CSjSplitterDoc* CSjSplitterView2::GetDocument() const
{
	return reinterpret_cast<CSjSplitterDoc*>(m_pDocument);
}
#endif


