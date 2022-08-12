
// SjData1View.h : CSjData1View Ŭ������ �������̽�
//

#pragma once


class CSjData1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjData1View();
	DECLARE_DYNCREATE(CSjData1View)

// Ư���Դϴ�.
public:
	CSjData1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CSjData1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // SjData1View.cpp�� ����� ����
inline CSjData1Doc* CSjData1View::GetDocument() const
   { return reinterpret_cast<CSjData1Doc*>(m_pDocument); }
#endif

