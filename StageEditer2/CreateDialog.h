#pragma once
#include "resource.h"
#include <commdlg.h>
#include "Map.h"


class CreateDialog{
	static TCHAR width[64];
	static TCHAR height[64];
public:
	static BOOL CALLBACK DialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static int GetWidth();
	static int GetHeight();
	static Map* CreateMap();
};