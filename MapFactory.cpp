#include "MapFactory.h"
#include <iostream>
#include <vector>
#include "DxLib.h"

using namespace std;

#define CELL_WIDTH	32		// セルの幅
#define CELL_HEIGHT 32		// セルの高さ


vector<string> split(const string &str, char delim){
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

Map* MapFactory::CreateMap(std::string fileName){
	const char* fileC = fileName.c_str();
	vector<int> orignal;
	char source[120];
	int charSize;			// 現在行のサイズ
	int fileHandle = FileRead_open(fileC);
	int x=0,y=0;

	//FileRead_gets(source,120,fileHandle);
	//y++;
	while(true){
		if(FileRead_gets(source,120,fileHandle)==-1)
			break;
		y++;
		// スプリット
		vector<string> item = split(source,',');
		x = item.size();
		for(int i=0;i<item.size();i++){
			orignal.push_back(atoi(item[i].c_str()));
		}
		//if(source[source.size()-1] == '\0')
			//break;
	}
	// 二次元配列生成
	int **mapdata;
	mapdata = (int**)malloc(sizeof(int*) * y);
	for (int i=0;i<y;i++) {
		mapdata[i] = (int*)malloc(sizeof(int) * x);
	}
	// データ格納
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			mapdata[i][j] = orignal[i*x + j];
		}
	}
	 
	Map *map = new Map(CELL_WIDTH,CELL_HEIGHT,mapdata);
	map->SetMapHeightAndWidth(y,x);
	return map;
}


#if 0
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
/*
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE prev,LPSTR cmd,int nShowCmd){
	// メモリリーク確認用
	::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);	

	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	// splitのテスト
	ClearDrawScreen();
	vector<string> v = split("10,10,10,10",',');
	for(int i=0;i<v.size();i++)
		DrawFormatString(0,i*30,GetColor(255,255,255),"%s",v[i].c_str());
	ScreenFlip();
	WaitKey();

	
	// MapFactoryのテスト
	ClearDrawScreen();
	MapFactory factory;
	Map* temp = factory.CreateMap("map.txt");
	DrawString(100,100,"OK",GetColor(255,255,255));
	ScreenFlip();
	WaitKey();

	// Mapのテスト
	ClearDrawScreen();
	int a = temp->GetMapData(49.5,49.5);
	int b = temp->GetMapData(50.5,50.5);
	DrawFormatString(100,100,GetColor(255,255,255),"a:%d b:%d",a,b);
	ScreenFlip();
	WaitKey();
	
	// デストラクタのテスト
	delete temp;
	DxLib_End();
}
*/
#endif
