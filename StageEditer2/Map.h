#pragma once
#include "stdafx.h"
#include "resource.h"
#include <commdlg.h>
#include <vector>

class Map{
private:
	int width;				// マップの幅
	int height;				// マップの高さ
	int offset;				// マップ描画オフセット値

	std::vector<int> orignal;		// マップデータ
	TCHAR *szFile;					// マップファイル名

	BITMAP renga;		// レンガ
	HDC rengaMem;		//
	BITMAP player;		// プレイヤー
	HDC playerMem;		//
	BITMAP kame;		// かめさん
	HDC kameMem;		//
	BITMAP coin;		// コイン
	HDC coinMem;		//	
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