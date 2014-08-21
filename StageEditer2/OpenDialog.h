#pragma once
#include "resource.h"
#include "stdafx.h"
#include <commdlg.h>
class Map;

class OpenDialog{
private:
	// 親のウィンドウ
	HWND			hWnd;
	// ファイル名の構造体
	OPENFILENAME	ofn;
	// ファイルパス
	TCHAR			szPath[MAX_PATH];
public:
	// コンストラクタ
	OpenDialog(HWND hWnd);
	// ファイルを開く
	TCHAR* FileOpen(HWND hWnd);
	// マップを生成する
	Map* CreateMap(char *filename);
};