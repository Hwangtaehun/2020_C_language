
// SjOdbc1Set.cpp : CSjOdbc1Set 클래스의 구현
//

#include "stdafx.h"
#include "SjOdbc1.h"
#include "SjOdbc1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSjOdbc1Set 구현

// 코드 생성 위치 2022년 11월 2일 수요일, 오후 3:21

IMPLEMENT_DYNAMIC(CSjOdbc1Set, CRecordset)

CSjOdbc1Set::CSjOdbc1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_strCode = L"";
	m_strName = L"";
	m_nKor = 0;
	m_nMat = 0;
	m_nEng = 0;
	m_nTotal = 0;
	m_dAverage = 0.0;
	m_nRank = 0;
	m_nFields = 8;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CSjOdbc1Set::GetDefaultConnect()
{
	return _T("DSN=SjTestDB;DBQ=C:\\\xc218\xac15\xc0dd\\\xd669\xd0dc\xd6c8\\Database\\SjTestDB.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CSjOdbc1Set::GetDefaultSQL()
{
	return _T("[Score]");
}

void CSjOdbc1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Text(pFX, _T("[strCode]"), m_strCode);
	RFX_Text(pFX, _T("[strName]"), m_strName);
	RFX_Long(pFX, _T("[nKor]"), m_nKor);
	RFX_Long(pFX, _T("[nMat]"), m_nMat);
	RFX_Long(pFX, _T("[nEng]"), m_nEng);
	RFX_Long(pFX, _T("[nTotal]"), m_nTotal);
	RFX_Double(pFX, _T("[dAverage]"), m_dAverage);
	RFX_Long(pFX, _T("[nRank]"), m_nRank);

}
/////////////////////////////////////////////////////////////////////////////
// CSjOdbc1Set 진단

#ifdef _DEBUG
void CSjOdbc1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSjOdbc1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

