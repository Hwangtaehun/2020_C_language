
// SjTest7View.h : CSjTest7View 클래스의 인터페이스
//

#pragma once


class CSjTest7View : public CView
{
protected: // serialization에서만 만들어집니다.
	CSjTest7View();
	DECLARE_DYNCREATE(CSjTest7View)

// 특성입니다.
public:
	CSjTest7Doc* GetDocument() const;

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
	virtual ~CSjTest7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDlg1();
	afx_msg void OnDlg2();
	afx_msg void OnControl();
	afx_msg void OnList();
	afx_msg void OnCalculator1();
	afx_msg void OnCalculator2();
	afx_msg void OnConvert();
	afx_msg void OnInput();
};

#ifndef _DEBUG  // SjTest7View.cpp의 디버그 버전
inline CSjTest7Doc* CSjTest7View::GetDocument() const
   { return reinterpret_cast<CSjTest7Doc*>(m_pDocument); }
#endif

