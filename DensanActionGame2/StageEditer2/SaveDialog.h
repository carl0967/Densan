#pragma once
#include "resource.h"
#include "stdafx.h"
#include <commdlg.h>
#include <vector>

class SaveDialog{
private:
	// 親のウィンドウ
	//HWND			hWnd;
	// ファイル名の構造体
	OPENFILENAME	ofn;
	// ファイルパス
	TCHAR			szPath[MAX_PATH];
public:
	SaveDialog(HWND hWnd);
	// ファイルを保存する
	void Save(char* filename,std::vector<int> orignal,int x,int y);
	// ファイルを保存する
	TCHAR* FileSave(HWND hWnd);
};