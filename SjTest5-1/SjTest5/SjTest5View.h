
// SjTest5View.h : CSjTest5View Ŭ������ �������̽�
//

#pragma once


class CSjTest5View : public CView
{
protected: // serialization������ ��������ϴ�.
	CSjTest5View();
	DECLARE_DYNCREATE(CSjTest5View)

// Ư���Դϴ�.
public:
	CSjTest5Doc* GetDocument() const;

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
	virtual ~CSjTest5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // SjTest5View.cpp�� ����� ����
inline CSjTest5Doc* CSjTest5View::GetDocument() const
   { return reinterpret_cast<CSjTest5Doc*>(m_pDocument); }
#endif

