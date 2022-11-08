// Student.h : CStudent Ŭ������ �����Դϴ�.



// CStudent �����Դϴ�.

// �ڵ� ���� ��ġ 2022�� 11�� 8�� ȭ����, ���� 3:39

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
// #error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
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
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
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
// CStudent ����

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


