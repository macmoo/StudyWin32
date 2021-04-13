#define WIN32_LEAN_AND_MEAN
#include <windows.h>
// ---------------------------------------------------------
// 함수 프로토타입
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
bool CreateMainWindow(HINSTANCE, int);
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);
// ---------------------------------------------------------
// 글로벌 변수
HINSTANCE hinst;
// ---------------------------------------------------------
// 상수
const char CLASS_NAME[]		= "WinMain";
const char APP_TITLE[]		= "Hello World";
const int  WINDOW_WIDTH		= 400;
const int  WINDOW_HEIGHT	= 400;
// ---------------------------------------------------------
// 윈도우 APP의 시작점
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;

	if (!CreateMainWindow(hinstance, nCmdShow))
		return false;

	// 메시지루프
	int done = 0;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
				done = 1;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}
// ---------------------------------------------------------
// 윈도우 이벤트콜백함수
LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
// ---------------------------------------------------------
// 윈도우 작성
bool CreateMainWindow(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX	wcx;
	HWND		hwnd;

	// 윈도우 클래스의 구조체
	wcx.cbSize			= sizeof(wcx);
	wcx.style			= CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc		= WinProc;
	wcx.cbClsExtra		= 0;
	wcx.cbWndExtra		= 0;
	wcx.hInstance		= hInstance;
	wcx.hIcon			= NULL;
	wcx.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wcx.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcx.lpszMenuName	= NULL;
	wcx.lpszClassName	= CLASS_NAME;
	wcx.hIconSm			= NULL;

	if (RegisterClassEx(&wcx) == 0)
		return false;
	
	hwnd = CreateWindow(CLASS_NAME
						, APP_TITLE
						, WS_OVERLAPPEDWINDOW
						, CW_USEDEFAULT
						, CW_USEDEFAULT
						, WINDOW_WIDTH
						, WINDOW_HEIGHT
						, (HWND)NULL
						, (HMENU)NULL
						, hInstance
						, (LPVOID)NULL);

	if (!hwnd)
		return false;
	
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	return true;
}
// ---------------------------------------------------------
