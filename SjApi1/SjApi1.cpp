// SjApi1.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "SjApi1.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;								// ���� �ν��Ͻ��Դϴ�.
TCHAR szTitle[MAX_LOADSTRING];					// ���� ǥ���� �ؽ�Ʈ�Դϴ�.
TCHAR szWindowClass[MAX_LOADSTRING];			// �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

void OnLButtonDown(HWND hWnd, UINT nFlags, POINT point);
void OnRButtonDown(HWND hWnd, UINT nFlags, POINT point);
void OnMouseMove(HWND hWnd, UINT nFlags, POINT point);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: ���⿡ �ڵ带 �Է��մϴ�.
	MSG msg;
	HACCEL hAccelTable;

	// ���� ���ڿ��� �ʱ�ȭ�մϴ�.
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SJAPI1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SJAPI1));

	// �⺻ �޽��� �����Դϴ�.
	while (GetMessage(&msg, NULL, 0, 0))
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
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SJAPI1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	//wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	//wcex.hbrBackground = (HBRUSH)(LTGRAY_BRUSH);
	//wcex.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SJAPI1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	//wcex.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_INFORMATION));

	return RegisterClassEx(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND	- ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT	- �� â�� �׸��ϴ�.
//  WM_DESTROY	- ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect = { 100, 100, 200, 200 };
	int x, y;
	TCHAR str[] = _T(" Mouse ��ġ�� ������ ");

	POINT point;
	point.x = LOWORD(lParam);
	point.y = HIWORD(lParam);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �޴� ������ ���� �м��մϴ�.
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
		/*TextOut(hdc, 100, 50, _T("WM_PAINT"), 8);*/
		SetBkMode(hdc, OPAQUE);
		SetTextColor(hdc, RGB(0, 0, 255));
		SetBkColor(hdc, RGB(0, 255, 0));
		TextOut(hdc, 200, 200, _T(" ���ڻ��� ���� "), 10);
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		OnLButtonDown(hWnd, wParam, point);
		break;

	case WM_RBUTTONDOWN:
		OnRButtonDown(hWnd, wParam, point);
		break;

	case WM_MOUSEMOVE:
		OnMouseMove(hWnd, wParam, point);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
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

void OnLButtonDown(HWND hWnd, UINT nFlags, POINT point)
{
	HDC hdc;
	TCHAR str[] = _T(" �Լ��� �и��� ���ʹ�ư");
	hdc = GetDC(hWnd);
	/*TextOut(hdc, 100, 150, _T("���ʹ�ư"), 4);*/
	//x = LOWORD(lParam);
	//y = HIWORD(lParam);
	SetTextAlign(hdc, TA_RIGHT | TA_BOTTOM);
	SetTextColor(hdc, RGB(0, 0, 255));
	SetBkColor(hdc, RGB(0, 255, 0));
	TextOut(hdc, point.x, point.y, (LPCTSTR)str, sizeof(str) / sizeof(TCHAR)-1);
	ReleaseDC(hWnd, hdc);
}

void OnRButtonDown(HWND hWnd, UINT nFlags, POINT point)
{
	HDC hdc;
	TCHAR str[] = _T(" �Լ��� �и��� �����ʹ�ư");
	hdc = GetDC(hWnd);
	/*DrawText(hdc, _T("DrawText ����"), -1, &rect, DT_LEFT | DT_WORDBREAK);*/
	/*x = LOWORD(lParam);
	y = HIWORD(lParam);*/
	SetTextAlign(hdc, TA_LEFT | TA_TOP);
	SetTextColor(hdc, RGB(0, 0, 255));
	SetBkColor(hdc, RGB(0, 255, 0));
	TextOut(hdc, point.x, point.y, str, _countof(str) - 1);
	ReleaseDC(hWnd, hdc);
}

void OnMouseMove(HWND hWnd, UINT nFlags, POINT point)
{
	HDC hdc = GetDC(hWnd);
	if (nFlags == MK_LBUTTON)
	{
		for (int i = 0; i < 30; i++)
		{
			SetPixel(hdc, point.x + (rand() % 30 -15), point.y + (rand() % 30 -15), RGB(0, 0, 255));
		}
	}
	ReleaseDC(hWnd, hdc);
}