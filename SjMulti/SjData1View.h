
// SjData1View.h : CSjData1View 클래스의 인터페이스
//

#pragma once


class CSjData1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CSjData1View();
	DECLARE_DYNCREATE(CSjData1View)

// 특성입니다.
public:
	CSjData1Doc* GetDocument() const;

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
	virtual ~CSjData1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_nSize;
	int m_nWidth;
	COLORREF m_penColor;
	COLORREF m_brushColor;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void DrawRect(CDC * pDC, CPoint point);
	void DrawRect(CDC * pDC, CPoint point, int nSize);
	void DrawRect(CDC * pDC, CPoint point, int nSize, int nWidth, COLORREF penColor, COLORREF brushColor);
	afx_msg void OnPenWidth1();
	afx_msg void OnPenWidth2();
	afx_msg void OnPenWidth3();
	afx_msg void OnPenRed();
	afx_msg void OnPenGreen();
	afx_msg void OnPenBlue();
	afx_msg void OnBrushRed();
	afx_msg void OnBrushGreen();
	afx_msg void OnBrushBlue();
	afx_msg void OnPenCustom();
	afx_msg void OnBrushCustom();
	afx_msg void OnOne();
	afx_msg void OnTwo();
	afx_msg void OnThree();
	afx_msg void OnSizeCustom();
	afx_msg void OnPenWidthCustom();
	//void DrawRect(CDC * pDC, DATA * pData);
	void DrawRect(CDC * pDC, CData * pData);
};

#ifndef _DEBUG  // SjData1View.cpp의 디버그 버전
inline CSjData1Doc* CSjData1View::GetDocument() const
   { return reinterpret_cast<CSjData1Doc*>(m_pDocument); }
#endif

