/*
どのセル座標のオブジェクトがどのIDかを管理するクラス
*/

#pragma once
#include "AObject.h"
#include "Map.h"

class ObjectManager{
public:
	ObjectManager();
	ObjectManager(int map_width,int map_height); //コンストラクタ。引数はセルの座標
	int FindObject(int cell_x,int cell_y,MapChip map_chip); //オブジェクトをみつけたときに呼び出す。idを返す
	int GetId(int cell_x,int cell_y); //テスト用関数
	TwoDimension GetCellPosFromId(int id); //idを引数にとって、セルの座標を返す
	~ObjectManager(); //デストラクタ
private:
	int** ids; //idを保持しておくための２次元配列(のポインタ)。
	int id_counter; //idを割り振るためのカウンター
	int width; //横の配列数
	int height; //縦の配列数
};