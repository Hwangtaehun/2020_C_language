
// SjData1Doc.h : CSjData1Doc 클래스의 인터페이스
//


#pragma once
#include "data.h"

//struct DATA
//{
//	CPoint m_Point;
//	int m_nSize;
//	int m_nWidth;
//	COLORREF m_penColor;
//	COLORREF m_burshColor;
//
//	void LoadSave(CArchive &ar)
//	{
//		if (ar.IsStoring())
//		{
//			ar << m_Point;
//			ar << m_nSize;
//			ar << m_nWidth;
//			ar << m_penColor;
//			ar << m_burshColor;
//		}
//		else
//		{
//			ar >> m_Point;
//			ar >> m_nSize;
//			ar >> m_nWidth;
//			ar >> m_penColor;
//			ar >> m_burshColor;
//		}
//	}
//};

class CSjData1Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CSjData1Doc();
	DECLARE_DYNCREATE(CSjData1Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CSjData1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	int m_nCnt;
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	/*CPoint m_aPoint[30];
	int m_aSize[30];
	int m_aWidth[30];
	COLORREF m_aPenColor[30];
	COLORREF m_aBurshColor[30];*/
	//DATA m_bData[30];
	//CData m_bData[30];
	//CObList m_List;
	//CTypedPtrList <CObList, CData*> m_List;
	CList<CData, CData&> m_List;
};
