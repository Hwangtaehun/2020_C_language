
// SjTest5View.h : CSjTest5View 클래스의 인터페이스
//

#pragma once


class CSjTest5View : public CView
{
protected: // serialization에서만 만들어집니다.
	CSjTest5View();
	DECLARE_DYNCREATE(CSjTest5View)

// 특성입니다.
public:
	CSjTest5Doc* GetDocument() const;

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
	virtual ~CSjTest5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_sw;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int nX;
	int nY;
	int nCX;
	int nCY;
	CRect m_Rect;
	int m_nHeight;
	int m_nWidth;
	int m_nRx;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void DrawRacket(bool bFlag, int a, int b, int c, int d);
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void DrawRacketOther(bool bFlag);
	int m_nRy;
};

#ifndef _DEBUG  // SjTest5View.cpp의 디버그 버전
inline CSjTest5Doc* CSjTest5View::GetDocument() const
   { return reinterpret_cast<CSjTest5Doc*>(m_pDocument); }
#endif

