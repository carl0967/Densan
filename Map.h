﻿#pragma once
#include <string>

//マップチップのデータが何を表すか列挙
//EMPTY=0 WALL=1 ...
enum MapChip{EMPTY,WALL,PLAYER,KAME };

class Map{
public:

private:
	int background_;	// 背景画像
	int cell_width;		// マップの1セルの幅
	int cell_hegiht;	// マップの1セルの高さ
	int map_width_;		// マップの全体の幅
	int map_height_;	// マップの全体の高さ
	int** map_datas;	// マップチップデータ
	int offset_;		// 表示画面領域が全体マップから見てどこかをあらわすための変数
						// セル単位ではなくピクセル単位(右に30スクロールするなら、offset=30に
						// して、描画するとき(x-ofset,y)が描画場所になる
	int wallGraph_;		// 壁の画像
	int width_;			// 背景画像の幅
public:
	int map_width() {return map_width_;}
	int map_height() {return map_height_;}

	Map();

	Map(int cell_width,int cell_hegiht,int** map_datas);		// コンストラクタ
	int GetMapData(double x,double y);							// 描画領域のx,y座標を引数にとって、
																// マップデータの配列の該当する場所に何があるかを返す
	int SetBackground(std::string filename);					// 背景画像を設定
	int GetMapDataFromCell(int x,int y);						// セルの座標からマップデータを取得
	void Draw();						// 描画
	void Draw(int offset);				// 描画
	void Scroll(int);					// offsetを動かす
	~Map();								// デストラクタ

	void SetMapHeightAndWidth(int height,int width);		// マップ全体の高さと幅を設定する
};