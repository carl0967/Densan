#pragma once
#include "stdafx.h"
#include "resource.h"
#include <commdlg.h>
#include <vector>
#define GRAPHIC_NUM 8

class Map{
	enum MapChip{EMPTY,WALL,PLAYER,KAME,COIN,G_FLAG,FLYKAME,TAIHO};
private:
	int width;				// マップの幅
	int height;				// マップの高さ
	int offset;				// マップ描画オフセット値

	std::vector<int> orignal;		// マップデータ
	TCHAR *szFile;					// マップファイル名

	BITMAP graphics[GRAPHIC_NUM];	// 画像データのビットマップ
	HDC	graphicMem[GRAPHIC_NUM];	// 画像データのメモリ
public:
	Map(int,int,std::vector<int>);
	// マップを読み込む
	VOID LoadMap(HWND hWnd);
	// 描画する
	VOID DrawMap(HWND hWnd,PAINTSTRUCT *ps,HDC hdc);
	// マップデータを循環させる
	void AddMapData(int xPos,int yPos,HWND hWnd);
	// セッター
	void setOffset(int offset){this->offset=offset;}
	// ゲッター
	int getOffset(){return offset;}
	int getWidth(){return width;}
	int getHeight(){return height;}
	std::vector<int> getMapdata(){return orignal;}

};