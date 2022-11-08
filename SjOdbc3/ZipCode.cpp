// ZipCode.h : CZipCode 클래스의 구현입니다.



// CZipCode 구현입니다.

// 코드 생성 위치 2022년 11월 8일 화요일, 오후 3:41

#include "stdafx.h"
#include "ZipCode.h"
IMPLEMENT_DYNAMIC(CZipCode, CRecordset)

CZipCode::CZipCode(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ZIPCODE = L"";
	m_SIDO = L"";
	m_GUGUN = L"";
	m_DONG = L"";
	m_RI = L"";
	m_BLDG = L"";
	m_ST_BUNJI = L"";
	m_ED_BUNJI = L"";
	m_SEQ = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
// #error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CZipCode::GetDefaultConnect()
{
	return _T("DSN=SjTestDB;DBQ=C:\\\xc218\xac15\xc0dd\\\xd669\xd0dc\xd6c8\\Database\\SjTestDB.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CZipCode::GetDefaultSQL()
{
	return _T("[ZipCode]");
}

void CZipCode::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Text(pFX, _T("[ZIPCODE]"), m_ZIPCODE);
	RFX_Text(pFX, _T("[SIDO]"), m_SIDO);
	RFX_Text(pFX, _T("[GUGUN]"), m_GUGUN);
	RFX_Text(pFX, _T("[DONG]"), m_DONG);
	RFX_Text(pFX, _T("[RI]"), m_RI);
	RFX_Text(pFX, _T("[BLDG]"), m_BLDG);
	RFX_Text(pFX, _T("[ST_BUNJI]"), m_ST_BUNJI);
	RFX_Text(pFX, _T("[ED_BUNJI]"), m_ED_BUNJI);
	RFX_Text(pFX, _T("[SEQ]"), m_SEQ);

}
/////////////////////////////////////////////////////////////////////////////
// CZipCode 진단

#ifdef _DEBUG
void CZipCode::AssertValid() const
{
	CRecordset::AssertValid();
}

void CZipCode::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


