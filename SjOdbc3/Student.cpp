// Student.h : CStudent 클래스의 구현입니다.



// CStudent 구현입니다.

// 코드 생성 위치 2022년 11월 8일 화요일, 오후 3:39

#include "stdafx.h"
#include "Student.h"
IMPLEMENT_DYNAMIC(CStudent, CRecordset)

CStudent::CStudent(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_strCode = L"";
	m_strName = L"";
	m_strZipCode = L"";
	m_strLastAddress = L"";
	m_strCellPhoneNumber = L"";
	m_strHomePhoneNumber = L"";
	m_dBirthDay;
	m_strEmail = L"";
	m_RegistrationNumber = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
// #error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CStudent::GetDefaultConnect()
{
	return _T("DSN=SjTestDB;DBQ=C:\\\xc218\xac15\xc0dd\\\xd669\xd0dc\xd6c8\\Database\\SjTestDB.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CStudent::GetDefaultSQL()
{
	return _T("[Student]");
}

void CStudent::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Text(pFX, _T("[strCode]"), m_strCode);
	RFX_Text(pFX, _T("[strName]"), m_strName);
	RFX_Text(pFX, _T("[strZipCode]"), m_strZipCode);
	RFX_Text(pFX, _T("[strLastAddress]"), m_strLastAddress);
	RFX_Text(pFX, _T("[strCellPhoneNumber]"), m_strCellPhoneNumber);
	RFX_Text(pFX, _T("[strHomePhoneNumber]"), m_strHomePhoneNumber);
	RFX_Date(pFX, _T("[dBirthDay]"), m_dBirthDay);
	RFX_Text(pFX, _T("[strEmail]"), m_strEmail);
	RFX_Text(pFX, _T("[RegistrationNumber]"), m_RegistrationNumber);

}
/////////////////////////////////////////////////////////////////////////////
// CStudent 진단

#ifdef _DEBUG
void CStudent::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudent::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


