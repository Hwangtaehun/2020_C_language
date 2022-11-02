
// SjOdbc1View.h : CSjOdbc1View 클래스의 인터페이스
//

#pragma once

class CSjOdbc1Set;

class CSjOdbc1View : public CRecordView
{
protected: // serialization에서만 만들어집니다.
	CSjOdbc1View();
	DECLARE_DYNCREATE(CSjOdbc1View)

public:
	enum{ IDD = IDD_SJODBC1_FORM };
	CSjOdbc1Set* m_pSet;

// 특성입니다.
public:
	CSjOdbc1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CSjOdbc1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SjOdbc1View.cpp의 디버그 버전
inline CSjOdbc1Doc* CSjOdbc1View::GetDocument() const
   { return reinterpret_cast<CSjOdbc1Doc*>(m_pDocument); }
#endif

