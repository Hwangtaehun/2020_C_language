// SjApiTetris.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "SjApiTetris.h"

#define MAX_LOADSTRING 100
#define COL_CNT 10
#define ROW_CNT 20
#define START_X 10
#define START_Y 10
#define BLOCK_SIZE 32

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

HWND g_hWnd;
HDC g_hdc;
HDC g_BackDC, g_BlockDC, g_NumberDC;
HBITMAP g_bmBack, g_bmBlock, g_bmNumber;
char g_Table[ROW_CNT][COL_CNT];
RECT g_mainRect;
RECT g_nextRect;
int g_nPattern;
int g_nBitType;
int g_nRot;
int g_nX, g_nY;
int g_nScore;
int g_nNextPattern;

POINT Pattern[7][16] =
{
    {{0,0},{0,-1},{-1,0},{-1,-1}, {0,0},{0,-1},{-1,0},{-1,-1}, {0,0},{0,-1},{-1,0},{-1,-1}, {0,0},{0,-1},{-1,0},{-1,-1}},
    {{0,0},{1,0},{-1,0},{-2,0}, {0,0},{0,1},{0,2},{0,-1}, {0,0},{1,0},{-1,0},{-2,0}, {0,0},{0,1},{0,2},{0,-1}},
    {{0,0},{-1,0},{0,-1},{1,-1}, {0,0},{0,1},{-1,0},{-1,-1}, {0,0},{-1,0},{0,-1},{1,-1}, {0,0},{0,1},{-1,0},{-1,-1}},
    {{0,0},{-1,-1},{0,-1},{1,0}, {0,0},{-1,0},{-1,1},{0,-1}, {0,0},{-1,-1},{0,-1},{1,0}, {0,0},{-1,0},{-1,1},{0,-1}},
    {{-1,0},{-1,1},{0,1},{1,1}, {0,1},{1,1},{1,0},{1,-1}, {-1,-1},{0,-1},{1,-1},{1,0}, {0,-1},{-1,-1},{-1,0},{-1,1}},
    {{-1,1},{0,1},{1,1},{1,0}, {0,-1},{1,-1},{1,0},{1,1}, {-1,0},{-1,-1},{0,-1},{1,-1}, {-1,1},{-1,0},{-1,-1},{0,1}},
    {{0,0},{-1,0},{1,0},{0,1}, {0,0},{0,-1},{0,1},{1,0}, {0,0},{-1,0},{1,0},{0,-1}, {0,0},{-1,0},{0,-1},{0,1}}
};

POINT nextPattern[7][4] =
{
    {{-1, 0}, {0, 0}, {-1, 1}, {0, 1}},
    {{-1, 1}, {0, 1}, {1, 1}, {-2, 1}},
    {{0, 1}, {-1, 1}, {0, 0}, {1, 0}},
    {{0, 1}, {-1, 0}, {0, 0}, {1, 1}},
    {{-1, 1}, {-1, 0}, {0, 1}, {1, 1}},
    {{1, 1}, {0, 1}, {-1, 1}, {1, 0}},
    {{0, 1}, {-1, 1}, {1, 1}, {0, 0}}
};

void OnCreate(HWND hWnd);
void DrawScreen();
void InitialGame();
void DrawBlock(BOOL bFlag);
BOOL BlockDown();
void MoveLeft();
void MoveRight();
void MoveDown();
void RolateBlock();
BOOL IsAround(int nX, int nY);
void SetTable();
void DisplayScore(int nScore);
void NextBlock(bool bFlag);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SJAPITETRIS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SJAPITETRIS));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SJAPITETRIS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SJAPITETRIS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   g_mainRect.left = START_X;
   g_mainRect.top = START_Y;
   g_mainRect.right = START_X + BLOCK_SIZE * COL_CNT + 4;
   g_mainRect.bottom = START_Y + BLOCK_SIZE * ROW_CNT + 4;
   g_nextRect.left = START_X + BLOCK_SIZE * COL_CNT + 20;
   g_nextRect.top = START_Y + 30;
   g_nextRect.right = g_nextRect.left + 130;
   g_nextRect.bottom = g_nextRect.top + 80;
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      //CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 
       100, 100, g_nextRect.right + 25, g_mainRect.bottom + 65, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   g_hWnd = hWnd;

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            //int wmEvent = HIWORD(wParam);
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case IDM_START:
                InitialGame();
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            DrawScreen();
            EndPaint(hWnd, &ps);
            break;
        }
    case WM_CREATE:
        OnCreate(hWnd);
        break;
    case WM_TIMER:
        BlockDown();
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            MoveLeft();
            break;
        case VK_RIGHT:
            MoveRight();
            break;
        case VK_DOWN:
            BlockDown();
            break;
        case VK_UP:
            RolateBlock();
            break;
        case VK_SPACE:
        case VK_RETURN:
            MoveDown();
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void OnCreate(HWND hWnd)
{
    g_hdc = GetDC(hWnd);
    g_nX = COL_CNT / 2;
    g_nY = 0;
    g_nPattern = 0;
    g_nRot = 0;
    g_nBitType = 1;
    g_nScore = 0;

    g_BlockDC = CreateCompatibleDC(g_hdc);
    g_BackDC = CreateCompatibleDC(g_hdc);
    g_NumberDC = CreateCompatibleDC(g_hdc);
    g_bmBlock = LoadBitmap(hInst, (LPCTSTR)IDB_BLOCK);
    g_bmBack = LoadBitmap(hInst, (LPCTSTR)IDB_BACK2);
    g_bmNumber = LoadBitmap(hInst, (LPCTSTR)IDB_NUMBER);
    SelectObject(g_BlockDC, g_bmBlock);
    SelectObject(g_BackDC, g_bmBack);
    SelectObject(g_NumberDC, g_bmNumber);

    memset((void*)g_Table, -1, sizeof(g_Table));
}

void DrawScreen()
{
    int row, col;
    Rectangle(g_hdc, START_X, START_Y, g_mainRect.right, g_mainRect.bottom);
    Rectangle(g_hdc, g_nextRect.left, g_nextRect.top, g_nextRect.right, g_nextRect.bottom);
    for (row = 0; row < ROW_CNT; row++)
    {
        for (col = 0; col < COL_CNT; col++)
        {
            if (g_Table[row][col] == -1)
            {
                BitBlt(g_hdc, START_X + 2 + col * BLOCK_SIZE, START_Y + 2 + row * BLOCK_SIZE, 
                    BLOCK_SIZE, BLOCK_SIZE, g_BackDC, col * BLOCK_SIZE, row * BLOCK_SIZE, SRCCOPY);
            }
            else
            {
                BitBlt(g_hdc, START_X + 2 + col * BLOCK_SIZE, START_Y + 2 + row * BLOCK_SIZE, 
                    BLOCK_SIZE, BLOCK_SIZE, g_BlockDC, g_Table[row][col] * BLOCK_SIZE, g_nBitType * BLOCK_SIZE, SRCCOPY);
            }
        }
    }
    DisplayScore(g_nScore);
}

void InitialGame()
{
    memset((void*)g_Table, -1, sizeof(g_Table));
    g_nPattern = rand() % 7;
    g_nRot = 0;
    g_nY = 1;
    g_nX = COL_CNT / 2;
    g_nScore = 0;
    DrawScreen();
    DrawBlock(TRUE);
    g_nNextPattern = rand() % 7;
    NextBlock(TRUE);
    SetTimer(g_hWnd, 1, 500, NULL);
}

void DrawBlock(BOOL bFlag)
{
    for (int i = 0; i < 4; i++)
    {
        if (bFlag)
        {
            BitBlt(g_hdc, START_X + 2 + (g_nX + Pattern[g_nPattern][i + g_nRot * 4].x) * BLOCK_SIZE,
                START_Y + 2 + (g_nY + Pattern[g_nPattern][i + g_nRot * 4].y) * BLOCK_SIZE,
                BLOCK_SIZE, BLOCK_SIZE, g_BlockDC, g_nPattern * BLOCK_SIZE, g_nBitType * BLOCK_SIZE, SRCCOPY);
        }
        else
        {
            BitBlt(g_hdc, START_X + 2 + (g_nX + Pattern[g_nPattern][i + g_nRot * 4].x) * BLOCK_SIZE,
                START_Y + 2 + (g_nY + Pattern[g_nPattern][i + g_nRot * 4].y) * BLOCK_SIZE,
                BLOCK_SIZE, BLOCK_SIZE, g_BackDC, (g_nX + Pattern[g_nPattern][i + g_nRot * 4].x) * BLOCK_SIZE, 
                (g_nY + Pattern[g_nPattern][i + g_nRot * 4].y) * BLOCK_SIZE, SRCCOPY);
        }
    }
}

BOOL BlockDown()
{
    if (!IsAround(g_nX, g_nY + 1))
    {
        SetTable();
        return FALSE;
    }
    DrawBlock(FALSE);
    g_nY++;
    DrawBlock(TRUE);
    g_nScore++;
    DisplayScore(g_nScore);

    return TRUE;
}

void MoveLeft()
{
    if (!IsAround(g_nX - 1, g_nY))
        return;
    DrawBlock(FALSE);
    g_nX--;
    DrawBlock(TRUE);
}

void MoveRight()
{
    if (!IsAround(g_nX + 1, g_nY))
        return;
    DrawBlock(FALSE);
    g_nX++;
    DrawBlock(TRUE);
}

void MoveDown()
{
    while (BlockDown())
    {
        Sleep(30);
    }
}

void RolateBlock()
{
    int nRot = g_nRot;
    DrawBlock(FALSE);
    if (g_nRot < 3)
        g_nRot++;
    else {
        g_nRot = 0;
    }
    if (!IsAround(g_nX, g_nY))
        g_nRot = nRot;
    DrawBlock(TRUE);
}

BOOL IsAround(int nX, int nY)
{
    int i, row, col;
    for (i = 0; i < 4; i++)
    {
        col = nX + Pattern[g_nPattern][i + g_nRot * 4].x;
        row = nY + Pattern[g_nPattern][i + g_nRot * 4].y;
        if (col < 0 || col > COL_CNT - 1 || row < 1 || row > ROW_CNT - 1)
        {
            return FALSE;
        }
        if (g_Table[row][col] != -1)
        {
            return FALSE;
        }
    }
    return TRUE;
}

void SetTable()
{
    int i, row, col, sw;
    for (i = 0; i < 4; i++)
    {
        g_Table[g_nY + Pattern[g_nPattern][i + g_nRot * 4].y][g_nX + Pattern[g_nPattern][i + g_nRot * 4].x] = g_nPattern;
    }
    for (row = ROW_CNT - 1; row >= 0; row--)
    {
        sw = 0;
        for (col = 0; col < COL_CNT; col++)
        {
            if (g_Table[row][col] == -1)
                sw = -1;
        }
        if (sw == 0)
        {
            for (i = row; i > 0; i--)
            {
                for (col = 0; col < COL_CNT; col++)
                {
                    g_Table[i][col] = g_Table[i - 1][col];
                }
            }
            for (col = 0; col < COL_CNT; col++)
            {
                BitBlt(g_hdc, START_X + 2 + col * BLOCK_SIZE, START_Y + 2 + row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, g_BackDC, 0, 0, SRCCOPY);
                Sleep(20);
            }
            g_nScore += 10;
            DrawScreen();
            Sleep(100);
            row++;
        }
    }
    g_nX = COL_CNT / 2;
    g_nY = 1;
    g_nPattern = g_nNextPattern;
    //NextBlock(FALSE);
    g_nNextPattern = rand() % 7;
    //NextBlock(TRUE);
    //g_nPattern = rand() % 7;
    g_nRot = 1;
    if (!IsAround(g_nX, g_nY + 1))
    {
        KillTimer(g_hWnd, 1);
        MessageBox(g_hWnd, TEXT("GameOut"), TEXT("msg"), MB_OK);
        return;
    }
}

void DisplayScore(int nScore)
{
    int i, temp = nScore;
    for (i = 7; i >= 0; i--)
    {
        if (temp > 0)
        {
            BitBlt(g_hdc, g_nextRect.left + i * 13 + 10, g_nextRect.bottom + 70, 13, 23, g_NumberDC, 0, (temp % 10) * 23, SRCCOPY);
            temp /= 10;
        }
        else
        {
            BitBlt(g_hdc, g_nextRect.left + i * 13 + 10, g_nextRect.bottom + 70, 13, 23, g_NumberDC, 0, 11 * 23, SRCCOPY);
            temp /= 10;
        }
    }
}

void NextBlock(bool bFlag)
{
    // TODO: 여기에 구현 코드 추가.
    int i, x = 50, y = 10;
    if (g_nNextPattern == 0)
        x = 65;
    else if (g_nNextPattern == 1)
        x = 65, y = 0;

    if (bFlag)
    {
        for (i = 0; i < 4; i++)
        {
            BitBlt(g_hdc, g_nextRect.left + x + (nextPattern[g_nNextPattern][i].x) * BLOCK_SIZE,
                g_nextRect.top + y + (nextPattern[g_nNextPattern][i].y) * BLOCK_SIZE,
                BLOCK_SIZE, BLOCK_SIZE, g_BlockDC, g_nNextPattern * BLOCK_SIZE, g_nBitType * BLOCK_SIZE, SRCCOPY);
        }
    }
    else
    {
        Rectangle(g_hdc, g_nextRect.left, g_nextRect.top, g_nextRect.right, g_nextRect.bottom);
    }
}