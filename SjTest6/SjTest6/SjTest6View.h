
// SjTest6View.h : CSjTest6View 클래스의 인터페이스
//

#pragma once


class CSjTest6View : public CView
{
protected: // serialization에서만 만들어집니다.
	CSjTest6View();
	DECLARE_DYNCREATE(CSjTest6View)

// 특성입니다.
public:
	CSjTest6Doc* GetDocument() const;

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
	virtual ~CSjTest6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_pt1;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int m_nSize;
	COLORREF m_penColor;
	int m_nPattern;
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnOne();
	afx_msg void OnThree();
	afx_msg void OnFive();
	afx_msg void OnLine1();
	afx_msg void OnDiamond();
	afx_msg void OnRose();
	afx_msg void OnLissajous();
	int CenterLine(CDC * pDC, CRect rect);
	void GeoLine(CDC * pDC);
	void GeoDiamond(CDC * pDC);
	void GeoRose(CDC * pDC);
	void GeoLissajous(CDC * pDC);
	afx_msg void OnCustom();
	LOGFONT m_logFont;
	afx_msg void OnCustom1();
};

#ifndef _DEBUG  // SjTest6View.cpp의 디버그 버전
inline CSjTest6Doc* CSjTest6View::GetDocument() const
   { return reinterpret_cast<CSjTest6Doc*>(m_pDocument); }
#endif

