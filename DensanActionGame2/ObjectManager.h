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
	int RegisterObject(int cell_x,int cell_y,MapChip map_chip); //オブジェクトを登録する。 (登録したときのIDを返すけど別に使わないかも)
	int GetId(int cell_x,int cell_y); //指定された座標が初期値のオブジェクトのIDを返す
	TwoDimension GetCellPosFromId(int id); //idを引数にとって、セルの座標を返す
	~ObjectManager(); //デストラクタ
private:
	int** ids; //idを保持しておくための２次元配列(のポインタ)。
	int id_counter; //idを割り振るためのカウンター
	int width; //横の配列数
	int height; //縦の配列数
};