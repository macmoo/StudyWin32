#define WIN32_LEAN_AND_MEAN
#include <windows.h>
// ---------------------------------------------------------
// �Լ� ������Ÿ��
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
bool CreateMainWindow(HINSTANCE, int);
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);
// ---------------------------------------------------------
// �۷ι� ����
HINSTANCE	hinst;
HDC			hdc;
TCHAR		ch = ' ';
RECT		rect;
PAINTSTRUCT	ps;
// ---------------------------------------------------------
// ���
const char CLASS_NAME[]		= "WinMain";
const char APP_TITLE[]		= "Hello World";
const int  WINDOW_WIDTH		= 400;
const int  WINDOW_HEIGHT	= 300;
// ---------------------------------------------------------
// ������ APP�� ������
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;

	if (!CreateMainWindow(hinstance, nCmdShow))
		return false;

	// �޽�������
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
	// WinMain�� �ý������� ���ư����� ��ȯ���� WM_QUIT�޽����� wParam�Ķ���Ϳ� �����Ѵ�.
	return msg.wParam;
}
// ---------------------------------------------------------
// ������ �̺�Ʈ�ݹ��Լ�
LRESULT WINAPI WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_CHAR:
			// wParam�� ������ Ű�� �����ڵ尡 ����ִ�,
			switch (wParam) 
			{
				case 0x08:
				case 0x09:
				case 0x0A:
				case 0x0D:
				case 0x1B:
					MessageBeep((UINT)-1);
					return 0;
				default:
					ch = (TCHAR)wParam;
					// WM_PAINT �����߻���Ŵ
					InvalidateRect(hwnd, NULL, TRUE);
			}
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			GetClientRect(hwnd, &rect);
			TextOut(hdc, rect.right/2, rect.bottom/2, &ch, 1);
			EndPaint(hwnd, &ps);
			return 0;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}
// ---------------------------------- -----------------------
// ������ �ۼ�
bool CreateMainWindow(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX	wcx;
	HWND		hwnd;

	// ������ Ŭ������ ����ü
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
