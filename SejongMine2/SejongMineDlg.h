
// SejongMineDlg.h : 헤더 파일
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define BOX_START_X 13
#define BOX_START_Y 55
#define XCNT 30
#define YCNT 24

// CSejongMineDlg 대화 상자
class CSejongMineDlg : public CDialogEx
{
// 생성입니다.
public:
	CSejongMineDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SEJONGMINE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CDC* m_pDC;
	CBitmap m_bmBox;
	CBitmap m_bmNumber;
	CBitmap m_bmFace;
	CDC m_boxDC;
	CDC m_numberDC;
	CDC m_faceDC;
	CRect m_WndRect;
	CRect m_FaceRect;

	int m_BoxState[YCNT][XCNT];
	int m_BoxStyle[YCNT][XCNT];
	int m_nBoxCntX;
	int m_nBoxCntY;
	int m_nMineCnt;

	int m_nMine;
	int m_nTime;
	int m_nOpened;
	int m_nGameState;
	int m_nFace;

	BOOL m_bFirst;
	BOOL m_bLbuttonDown;
	BOOL m_bRbuttonDown;
	BOOL m_bTimerState;
	UINT m_nld;

	void ResizeWindow();
	void DrawBox(int x, int y, int style);
	void DrawFace(int style);
	void DrawMineCounter();
	void DrawTimer();
	void InitGame();
	void MineSetting(int dx, int dy);
	int CountMines(int x, int y);
	void LRButtonClick(int x, int y, bool bStyle);
	void ClickBox(int x, int y);
	void GameWin();
	void GameLose();
	void WriteFile();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBeginner();
	afx_msg void OnIntermediate();
	afx_msg void OnExperience();
	afx_msg void OnCustom();
	afx_msg void OnStart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	int m_nCustomTime;
	void Rank();
	afx_msg void OnTop();
	void RankSort(int n);
	CString m_strCustomName;
	afx_msg void OnExit();
	afx_msg void OnQuestion();
	afx_msg void OnColor();
	afx_msg void OnHelp();
	int m_nQuestion;
	CBitmap m_bmOBox;
	CBitmap m_bmONumber;
	CBitmap m_bmOFace;
	int m_nColor;
};
