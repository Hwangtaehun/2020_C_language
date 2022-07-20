
// SjTest1Doc.cpp: CSjTest1Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SjTest1.h"
#endif

#include "SjTest1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSjTest1Doc

IMPLEMENT_DYNCREATE(CSjTest1Doc, CDocument)

BEGIN_MESSAGE_MAP(CSjTest1Doc, CDocument)
	ON_COMMAND(IDM_UP, &CSjTest1Doc::OnUp)
	ON_COMMAND(IDM_DOWN, &CSjTest1Doc::OnDown)
	ON_COMMAND(IDM_LEFT, &CSjTest1Doc::OnLeft)
	ON_COMMAND(IDM_RIGHT, &CSjTest1Doc::OnRight)
END_MESSAGE_MAP()


// CSjTest1Doc 생성/소멸

CSjTest1Doc::CSjTest1Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

	m_nCnt = 0;
}

CSjTest1Doc::~CSjTest1Doc()
{
}

BOOL CSjTest1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CSjTest1Doc serialization

void CSjTest1Doc::Serialize(CArchive& ar)
{
	int i;
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		ar << m_nCnt;
		for (i = 0; i < m_nCnt; i++)
		{
			ar << m_Data[i];
		}
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		ar >> m_nCnt;
		for (i = 0; i < m_nCnt; i++)
		{
			ar >> m_Data[i];
		}
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CSjTest1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CSjTest1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSjTest1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSjTest1Doc 진단

#ifdef _DEBUG
void CSjTest1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSjTest1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSjTest1Doc 명령


void CSjTest1Doc::OnUp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	for (int i = 0; i < m_nCnt; i++)
	{
		m_Data[i].y -= 5;
	}
	UpdateAllViews(NULL);
}


void CSjTest1Doc::OnDown()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	for (int i = 0; i < m_nCnt; i++)
	{
		m_Data[i].y += 5;
	}
	UpdateAllViews(NULL);
}


void CSjTest1Doc::OnLeft()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	for (int i = 0; i < m_nCnt; i++)
	{
		m_Data[i].x -= 5;
	}
	UpdateAllViews(NULL);
}


void CSjTest1Doc::OnRight()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	for (int i = 0; i < m_nCnt; i++)
	{
		m_Data[i].x += 5;
	}
	UpdateAllViews(NULL);
}
