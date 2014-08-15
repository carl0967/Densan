/*
どのセル座標のオブジェクトがどのIDかを管理するクラス
*/

#pragma once

class ObjectManager{
public:
	ObjectManager();
	ObjectManager(int map_width,int map_height); //コンストラクタ。引数はセルの座標
	int FindObject(int cell_x,int cell_y); //オブジェクトをみつけたときに呼び出す。idを返す
	int GetId(int cell_x,int cell_y); //テスト用関数
	~ObjectManager(); //デストラクタ。未実装
private:
	int** ids; //idを保持しておくための２次元配列(のポインタ)。
	int id_counter; //idを割り振るためのカウンター
};