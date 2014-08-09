#pragma once

class Map{
private:
	int cell_width;		// マップの1セルの幅
	int cell_hegiht;	// マップの1セルの高さ
	int map_width;		// マップの全体の幅
	int map_hegiht;		// マップの全体の高さ
	int** map_datas;	// マップチップデータ
	int offset;			// 表示画面領域が全体マップから見てどこかをあらわすための変数
						// セル単位ではなくピクセル単位(右に30スクロールするなら、offset=30に
						// して、描画するとき(x-ofset,y)が描画場所になる
public:
	Map(int cell_width,int cell_hegiht,int** map_datas);		// コンストラクタ
	int GetMapData(double x,double y);	// 描画領域のx,y座標を引数にとって、
										// マップデータの配列の該当する場所に何があるかを返す
	void Scroll(int);	// offsetを動かす
	~Map();				// デストラクタ

	void SetMapHeightAndWidth(int height,int width);		// マップ全体の高さと幅を設定する
};