#pragma once

#include "AObject.h"
#include "Player.h"
#include "Item.h"
/*
アイテムである「コイン」を表す具象クラス
アイテムの実装例
とったらスコアが増える
*/

class Coin: public Item{
public:
	//コンストラクタ
	//x座標、ｙ座標、ファイル名（画像/画像ファイル名,オブジェクトの幅,オブジェクトの高さ,向き（右向きならtrue）
	Coin(double ax,double ay);
	//関数
	/*
	引数のplayerのフィールド変数を変更して、アイテムの効果を与える関数
	*/
	void Affect(Character* character);
	/*
	そのアイテムがどのような思考をするか（動き方とか）を決定する
	*/
	void Think();
	
protected:

	
private:


};