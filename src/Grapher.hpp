#pragma once

#include <windows.h>
#include <math.h>

#ifdef BUILD
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

namespace LineFunctions /* Biblioteka podstawowych funkcji liniowych do użycia w (function(long(long)),COLORREF) void)Graph::draw.
						Można definiować oczywiście własne funkcje  przekazywać je jako parametr.
						Przykład : {Graph g(???,???); g.draw(XtoY,0x00FF00);}
						rysuje korzystając z funkcji XtoY zieloną(?) kreskę kątem 45* względem osi X i Y w zwyż.
						Przykład wykresu narysowanego za pomocą tych funkcji znajduje się w pliku "Examples.bmp". */
{
	long cache;

	long XtoY(long X) { return X; } // Y = X
	long PingPong(long X, long Max) { if (X % (Max * 2) > Max) return X%Max; else return (Max - X) % Max; } // Y = X % Max if X % Max*2 > Max else Y = Max-X % Max
	long SinusWave(long X, long H) { if (H < 0) H = -H; return sin(X)*H; } // Y = sin (X) * H
	long SParable(long X) { return X*X; }

																		   //Funkcje konwertujące
	void setData(long ch) { cache = ch; }
	long PingPong(long X) { return PingPong(X, cache); }
	long SinusWave(long X) { return SinusWave(X, cache); }
}

class Graph
{
	POINT graphPoint;
	HWND hWND;
public: DLL Graph(HWND,POINT start);
		void DLL draw(long function(long), bool upd(), COLORREF color, ULONG = 0);
};
