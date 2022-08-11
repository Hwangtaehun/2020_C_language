
// SjData1Doc.cpp : CSjData1Doc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SjData1.h"
#endif

#include "SjData1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSjData1Doc

IMPLEMENT_DYNCREATE(CSjData1Doc, CDocument)

BEGIN_MESSAGE_MAP(CSjData1Doc, CDocument)
	ON_COMMAND(IDM_UP, &CSjData1Doc::OnUp)
	ON_COMMAND(IDM_DOWN, &CSjData1Doc::OnDown)
	ON_COMMAND(IDM_LEFT, &CSjData1Doc::OnLeft)
	ON_COMMAND(IDM_RIGHT, &CSjData1Doc::OnRight)
END_MESSAGE_MAP()


// CSjData1Doc ����/�Ҹ�

CSjData1Doc::CSjData1Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

	m_nCnt = 0;
}

CSjData1Doc::~CSjData1Doc()
{
}

BOOL CSjData1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CSjData1Doc serialization

void CSjData1Doc::Serialize(CArchive& ar)
{
	//int i;
	//if (ar.IsStoring())
	//{
	//	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	//	ar << m_nCnt;
	//	for (i = 0; i < m_nCnt; i++)
	//	{
	//		/*ar << m_aPoint[i];
	//		ar << m_aSize[i];
	//		ar << m_aWidth[i];
	//		ar << m_aPenColor[i];
	//		ar << m_aBurshColor[i];*/

	//		/*ar << m_bData[i].m_Point;
	//		ar << m_bData[i].m_nSize;
	//		ar << m_bData[i].m_nWidth;
	//		ar << m_bData[i].m_penColor;
	//		ar << m_bData[i].m_burshColor;*/

	//		//m_bData[i].LoadSave(ar);
	//		m_bData[i].Serialize(ar);
	//	}
	//}
	//else
	//{
	//	// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	//	ar >> m_nCnt;
	//	for (i = 0; i < m_nCnt; i++)
	//	{
	//		/*ar >> m_aPoint[i];
	//		ar >> m_aSize[i];
	//		ar >> m_aWidth[i];
	//		ar >> m_aPenColor[i];
	//		ar >> m_aBurshColor[i];*/

	//		/*ar >> m_bData[i].m_Point;
	//		ar >> m_bData[i].m_nSize;
	//		ar >> m_bData[i].m_nWidth;
	//		ar >> m_bData[i].m_penColor;
	//		ar >> m_bData[i].m_burshColor;*/

	//		//m_bData[i].LoadSave(ar);
	//		m_bData[i].Serialize(ar);
	//	}
	//}

	/*int i, cnt;
	CData* pNode;
	if (ar.IsStoring())
	{
		ar << m_List.GetCount();
		for (POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
		{
			pNode = (CData*)m_List.GetNext(pos);
			pNode->Serialize(ar);
		}
	}
	else
	{
		m_List.RemoveAll();
		ar >> cnt;
		for (i = 0; i < cnt; i++)
		{
			pNode = new CData;
			pNode->Serialize(ar);
			m_List.AddTail(pNode);
		}
	}*/

	int i, cnt;
	CData node, * pNode;
	if (ar.IsStoring())
	{
		ar << m_List.GetCount();
		for (POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
		{
			node = m_List.GetNext(pos);
			node.Serialize(ar);
		}
	}
	else
	{
		m_List.RemoveAll();
		ar >> cnt;
		for (i = 0; i < cnt; i++)
		{
			pNode = new CData;
			pNode->Serialize(ar);
			m_List.AddTail(*pNode);
		}
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CSjData1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CSjData1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSjData1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSjData1Doc ����

#ifdef _DEBUG
void CSjData1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSjData1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSjData1Doc ���


void CSjData1Doc::OnUp()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//for (int i = 0; i < m_nCnt; i++)
	//{
	//	//m_aPoint[i].y -= 5;
	//	//m_bData[i].m_Point.y += -5;
	//	m_bData[i].ModifyPoint(0, -5);
	//}

	/*CData* pNode;
	for (POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
	{
		pNode = (CData*)m_List.GetNext(pos);
		pNode->ModifyPoint(0, -5);
	}*/
	
	CData node;
	for (POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
	{
		node = m_List.GetAt(pos);
		node.ModifyPoint(0, -5);
		m_List.SetAt(pos, node);
		m_List.GetNext(pos);
	}

	UpdateAllViews(NULL);
}


void CSjData1Doc::OnDown()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//for (int i = 0; i < m_nCnt; i++)
	//{
	//	//m_aPoint[i].y += 5;
	//	//m_bData[i].m_Point.y += 5;
	//	m_bData[i].ModifyPoint(0, 5);
	//}

	/*CData* pNode;
	for (POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
	{
		pNode = (CData*)m_List.GetNext(pos);
		pNode->ModifyPoint(0, 5);
	}*/

	CData node;
	for (POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
	{
		node = m_List.GetAt(pos);
		node.ModifyPoint(0, 5);
		m_List.SetAt(pos, node);
		m_List.GetNext(pos);
	}

	UpdateAllViews(NULL);
}


void CSjData1Doc::OnLeft()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//for (int i = 0; i < m_nCnt; i++)
	//{
	//	//m_aPoint[i].x -= 5;
	//	//m_bData[i].m_Point.x += -5;
	//	m_bData[i].ModifyPoint(-5, 0);
	//}

	/*CData* pNode;
	for (POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
	{
		pNode = (CData*)m_List.GetNext(pos);
		pNode->ModifyPoint(-5, 0);
	}*/
	
	CData node;
	POSITION pos = m_List.GetHeadPosition();
	for (int i = 0; i < m_List.GetCount(); i++)
	{
		node = m_List.GetAt(pos);
		node.ModifyPoint(-5, 0);
		m_List.SetAt(pos, node);
		m_List.GetNext(pos);
	}
	UpdateAllViews(NULL);
}


void CSjData1Doc::OnRight()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//for (int i = 0; i < m_nCnt; i++)
	//{
	//	//m_aPoint[i].x += 5;
	//	//m_bData[i].m_Point.x += +5;
	//	m_bData[i].ModifyPoint(5, 0);
	//}

	/*CData* pNode;
	for (POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
	{
		pNode = (CData*)m_List.GetNext(pos);
		pNode->ModifyPoint(5, 0);
	}*/
	CData node;
	POSITION pos = m_List.GetHeadPosition();
	for (int i = 0; i < m_List.GetCount(); i++)
	{
		node = m_List.GetAt(pos);
		node.ModifyPoint(5, 0);
		m_List.SetAt(pos, node);
		m_List.GetNext(pos);
	}
	UpdateAllViews(NULL);
}
