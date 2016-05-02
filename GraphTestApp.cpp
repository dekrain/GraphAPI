#include "Grapher.hpp" // Includes "windows.h" and "math.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch( uMsg )
	{
		case WM_CLOSE:
        DestroyWindow( hWnd );
        break;
        
		case WM_DESTROY:
        PostQuitMessage( 0 );
        break;
		
		default: return DefWindowProc( hWnd, uMsg, wParam, lParam );
	}
	
	return 0;
}

bool Upd()
{
	MSG msg; 
	if ( GetMessage( &msg, NULL, 0, 0 )==NULL) return FALSE;
	
	TranslateMessage( & msg );
	DispatchMessage( & msg );
	
	return TRUE;
}

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpLine, INT nCmdShow)
{
	WNDCLASSEX wc;

	wc.cbSize = sizeof( WNDCLASSEX );
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
	wc.hCursor = LoadCursor( NULL, IDC_ARROW );
	wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "TestGrapher";
	wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );
	
	if( !RegisterClassEx( & wc ) )
		throw (char*)("Cannot register wnd class!!!");
	
	HWND hWnd = CreateWindowEx( WS_EX_CLIENTEDGE, "TestGrapher", "Grapher (v.1.0) test!", WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT, CW_USEDEFAULT, 600, 350, NULL, NULL, hInstance, NULL );
	
	if(hWnd == NULL)
		return 0xf4;
	
	ShowWindow( hWnd, nCmdShow );
	UpdateWindow( hWnd );
	
	class Graph gp( hWnd, {10,10} );
	gp.draw(LineFunctions::XtoY,Upd,0x0000FF,hWnd,1);
	LineFunctions::setData(200);
	gp.draw(LineFunctions::SinusWave,Upd,0x00FF00,hWnd,1);
	gp.draw(LineFunctions::PingPong,Upd,0xFF0000,hWnd,1);
	gp.draw(LineFunctions::SParable,Upd,0xFFFFFF,hWnd,1);
	
	MSG msg;
	while( GetMessage( & msg, NULL, 0, 0 ) )
	{
		TranslateMessage( & msg );
		DispatchMessage( & msg );
	}
	
	return 0;
}