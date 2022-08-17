
// SjBitmap1View.h : CSjBitmap1View 클래스의 인터페이스
//

#pragma once


class CSjBitmap1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CSjBitmap1View();
	DECLARE_DYNCREATE(CSjBitmap1View)

// 특성입니다.
public:
	CSjBitmap1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CSjBitmap1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CDC m_memDC;
	CBitmap m_bitMap;
	CBitmap m_bitMask;
	CBitmap m_bitBack;
	int m_nX;
	int m_nY;
	int m_xPos;
	int m_yPos;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // SjBitmap1View.cpp의 디버그 버전
inline CSjBitmap1Doc* CSjBitmap1View::GetDocument() const
   { return reinterpret_cast<CSjBitmap1Doc*>(m_pDocument); }
#endif

