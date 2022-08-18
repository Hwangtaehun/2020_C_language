
// SjBitmapShowView.h : CSjBitmapShowView 클래스의 인터페이스
//

#pragma once
#define BMP_COUNT 12
#define BMP_WIDTH 1024
#define BMP_HEIGHT 680

class CSjBitmapShowView : public CView
{
protected: // serialization에서만 만들어집니다.
	CSjBitmapShowView();
	DECLARE_DYNCREATE(CSjBitmapShowView)

// 특성입니다.
public:
	CSjBitmapShowDoc* GetDocument() const;

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
	virtual ~CSjBitmapShowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CBitmap m_Bitmap;
	CDC m_memDC;
	int m_nBitmap;
//	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnDestroy();
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void Vertical1(CDC * pDC);
	void Vertical2(CDC * pDC);
	void Vertical3(CDC * pDC);
	void Horizontal1(CDC * pDC);
	void Horizontal2(CDC * pDC);
	void Horizontal3(CDC * pDC);
	void In(CDC * pDC);
	void Out(CDC * pDC);
	void Snail(CDC * pDC);
	void Random(CDC * pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // SjBitmapShowView.cpp의 디버그 버전
inline CSjBitmapShowDoc* CSjBitmapShowView::GetDocument() const
   { return reinterpret_cast<CSjBitmapShowDoc*>(m_pDocument); }
#endif

