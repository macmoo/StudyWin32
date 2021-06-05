#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
bool CreateMainWindow(HINSTANCE, int);
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hinst;
HDC hdc;
TCHAR ch = ' ';
RECT rect;
PAINTSTRUCT ps;
bool vkKeys[256]; 


const char CLASS_NAME[] = "Keyboard";
const char APP_TITLE[] = "Character Input";
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGT = 300;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;

	if( !CreateMainWindow(hInstance, nCmdShow))
		return false;

	int done = 0;
	for (int i=0; i<256; i++)   // initialize virtual key array
        vkKeys[i] = false;


	while( !done )
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.wParam == WM_QUIT)
				done = 1;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

LRESULT WINAPI WinProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	short nVirtKey;
	const short SHIFTED = ( short)0x8000;
    TEXTMETRIC tm;                  // structure for text metrics
    DWORD chWidth = 20;             // width of characters
    DWORD chHeight = 20;            // height of characters

	switch(msg)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);
		GetTextMetrics(hdc, &tm);
		ReleaseDC(hwnd, hdc);
		chWidth = tm.tmAveCharWidth;
		chHeight = tm.tmHeight;
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		vkKeys[wParam] = true;
		switch(wParam)
		{
		case VK_SHIFT:
			nVirtKey = GetKeyState(VK_LSHIFT);
			if( nVirtKey & SHIFTED)
				vkKeys[VK_LSHIFT] = true;
			nVirtKey = GetKeyState(VK_RSHIFT);
			if( nVirtKey & SHIFTED)
				vkKeys[VK_RSHIFT] = true;
			break;
		case VK_CONTROL:
			nVirtKey = GetKeyState(VK_LCONTROL);
			if( nVirtKey & SHIFTED)
				vkKeys[VK_LCONTROL] = true;
			nVirtKey = GetKeyState(VK_RCONTROL);
			if( nVirtKey & SHIFTED)
				vkKeys[VK_RCONTROL] = true;
			break;
		}
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;
		break;
	case WM_KEYUP:
		vkKeys[wParam] = false;
		switch(wParam)
		{
		case VK_SHIFT:
			nVirtKey = GetKeyState(VK_LSHIFT);
			if( (nVirtKey & SHIFTED) == 0)
				vkKeys[VK_LSHIFT] = false;
			nVirtKey = GetKeyState(VK_RSHIFT);
			if( (nVirtKey & SHIFTED)==0)
				vkKeys[VK_RSHIFT] = false;
			break;
		case VK_CONTROL:
			nVirtKey = GetKeyState(VK_LCONTROL);
			if( (nVirtKey & SHIFTED)==0)
				vkKeys[VK_LCONTROL] = false;
			nVirtKey = GetKeyState(VK_RCONTROL);
			if( (nVirtKey & SHIFTED)==0)
				vkKeys[VK_RCONTROL] = false;
			break;
		}
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;
		break;
	case WM_PAINT:
		 hdc = BeginPaint(hwnd, &ps);    // get handle to device context
         TextOut(hdc, 0, 0, &ch, 1);     // display the character
          
         for ( int r=0; r<16; r++)
         {
			for ( int c=0; c<16; c++)
			{
				if (vkKeys[r*16+c])
                {
					SetBkMode(hdc, OPAQUE);         // opaque text background
                    TextOut(hdc,c*chWidth+chWidth*2,r*chHeight+chHeight*2, "T ", 2);
				} else {
					SetBkMode(hdc, TRANSPARENT);    // transparent text background
					TextOut(hdc,c*chWidth+chWidth*2,r*chHeight+chHeight*2, "F ", 2);
                }
			}
         }

	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

bool CreateMainWindow(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcx;
	HWND hwnd;

	wcx.cbSize = sizeof(wcx);
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WinProc;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hInstance;
	wcx.hIcon = NULL;
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcx.lpszMenuName = NULL;
	wcx.lpszClassName = CLASS_NAME;
	wcx.hIconSm = NULL;
	
	if(RegisterClassEx(&wcx) == 0)
		return false;

	hwnd = CreateWindow(CLASS_NAME, APP_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGT, (HWND)NULL, (HMENU)NULL, hInstance, (LPVOID)NULL);

	if(!hwnd)
		return false;
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	return true;

}