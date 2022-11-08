// ZipCode.h : CZipCode의 선언입니다.

#pragma once

// 코드 생성 위치 2022년 11월 8일 화요일, 오후 3:41

class CZipCode : public CRecordset
{
public:
	CZipCode(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CZipCode)

// 필드/매개 변수 데이터

// 아래의 문자열 형식(있을 경우)은 데이터베이스 필드의 실제 데이터 형식을
// 나타냅니다(CStringA:
// ANSI 데이터 형식, CStringW: 유니코드 데이터 형식).
// 이것은 ODBC 드라이버에서 불필요한 변환을 수행할 수 없도록 합니다.  // 원할 경우 이들 멤버를 CString 형식으로 변환할 수 있으며
// 그럴 경우 ODBC 드라이버에서 모든 필요한 변환을 수행합니다.
// (참고: 유니코드와 이들 변환을 모두 지원하려면  ODBC 드라이버
// 버전 3.5 이상을 사용해야 합니다).

	CStringW	m_ZIPCODE;	//우편번호
	CStringW	m_SIDO;	//시도이름
	CStringW	m_GUGUN;	//구군이름
	CStringW	m_DONG;	//동이름
	CStringW	m_RI;	//리이름
	CStringW	m_BLDG;	//검물/아파트이름
	CStringW	m_ST_BUNJI;	//시작번지
	CStringW	m_ED_BUNJI;	//마지막번지
	CStringW	m_SEQ;	//Primarykey

// 재정의
	// 마법사에서 생성한 가상 함수 재정의
	public:
	virtual CString GetDefaultConnect();	// 기본 연결 문자열

	virtual CString GetDefaultSQL(); 	// 레코드 집합의 기본 SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX 지원

// 구현
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


