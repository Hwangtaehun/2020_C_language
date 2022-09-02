#pragma once


// CExamAdd 대화 상자입니다.

class CExamAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CExamAdd)

public:
	CExamAdd(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExamAdd();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EXAM_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCheck1;
	CString m_strCheck2;
	CString m_strCheck3;
	CString m_strCheck4;
	CString m_strCheck5;
	CString m_strCheck6;
	CString m_strCheck7;
	CString m_strCheck8;
	CString m_strCheck9;
	CString m_strExam1;
	CString m_strExam2;
	CString m_strExam3;
	CString m_strExam4;
	CString m_strExam5;
	CString m_strExam6;
	CString m_strExam7;
	CString m_strExam8;
	CString m_strExam9;
};
