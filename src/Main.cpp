
//Main.cpp :: Extention\Dynamic-Link Library :: Grapher.dll
//struct POINT {double(?) x,y};

#include "Grapher.hpp"
	
	DLL Graph:: Graph(HWND hWND, POINT startPoint)
	{
		HDC hDC = GetDC(hWND);
		{
			HBRUSH brush, old_brush;
			HPEN pen, old_pen;
			brush = CreateSolidBrush(RGB(192,192,192));
			pen = CreatePen(PS_SOLID,1,0);
			old_brush = (HBRUSH) SelectObject(hDC,brush);
			old_pen = (HPEN) SelectObject(hDC,pen);
		
			Rectangle(hDC,startPoint.x,startPoint.y,startPoint.x+500,startPoint.y+250);
			SelectObject(hDC,old_brush);
			SelectObject(hDC,old_pen);
			DeleteObject(brush);
			DeleteObject(pen);
		}
		ReleaseDC(hWND,hDC);
		
		graphPoint = startPoint;
		graphPoint.y += 250;
	}

	void DLL Graph::draw(long Line(long), bool Update(), COLORREF LineColor, HWND hWND, ULONG time)
	{
		HDC hDC = GetDC(hWND); POINT old_Point;
		{
			HPEN pen, old_pen;
			pen = CreatePen(PS_SOLID, 1, LineColor);
			old_pen = (HPEN)SelectObject(hDC, pen);

			MoveToEx(hDC, graphPoint.x, graphPoint.y, &old_Point);
			for (long x = 0; x < 500; x++) // x to pozycja osi X. Funkcja ta (kawałek kodu) służy za ryzowanie lini z pixela do pixela po jednym z danego punktu do punkty na osi Y.
			{
				if (!(Line(x) > 250 || Line(x) < 0))LineTo(hDC, x, 250 - Line(x)); _sleep(time); Update();
			}

			MoveToEx(hDC, old_Point.x, old_Point.y, NULL);
			SelectObject(hDC, old_pen);
			DeleteObject(pen);
		}
		ReleaseDC(hWND, hDC);
	}
