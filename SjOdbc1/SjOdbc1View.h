
// SjOdbc1View.h : CSjOdbc1View Ŭ������ �������̽�
//

#pragma once

class CSjOdbc1Set;

class CSjOdbc1View : public CRecordView
{
protected: // serialization������ ��������ϴ�.
	CSjOdbc1View();
	DECLARE_DYNCREATE(CSjOdbc1View)

public:
	enum{ IDD = IDD_SJODBC1_FORM };
	CSjOdbc1Set* m_pSet;

// Ư���Դϴ�.
public:
	CSjOdbc1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CSjOdbc1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SjOdbc1View.cpp�� ����� ����
inline CSjOdbc1Doc* CSjOdbc1View::GetDocument() const
   { return reinterpret_cast<CSjOdbc1Doc*>(m_pDocument); }
#endif

