
// SjThread4View.h : CSjThread4View 클래스의 인터페이스
//

#pragma once


class CSjThread4View : public CView
{
protected: // serialization에서만 만들어집니다.
	CSjThread4View();
	DECLARE_DYNCREATE(CSjThread4View)

// 특성입니다.
public:
	CSjThread4Doc* GetDocument() const;

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
	virtual ~CSjThread4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCriticalSection1();
	afx_msg void OnCriticalSection2();
	afx_msg void OnCriticalSection3();
	afx_msg void OnEvent1();
	afx_msg void OnEvent2();
	afx_msg void OnPulseEvent();
	afx_msg void OnResetevent();
	afx_msg void OnSetEvent();
};

#ifndef _DEBUG  // SjThread4View.cpp의 디버그 버전
inline CSjThread4Doc* CSjThread4View::GetDocument() const
   { return reinterpret_cast<CSjThread4Doc*>(m_pDocument); }
#endif

