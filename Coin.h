#pragma once

#include "AObject.h"
#include "Player.h"
/*
アイテムである「コイン」を表す具象クラス
アイテムの実装例?
*/

class Coin extends Item{
public:
	//コンストラクタ
	//x座標、ｙ座標、ファイル名（画像/画像ファイル名,オブジェクトの幅,オブジェクトの高さ,向き（右向きならtrue）
	Coin(double ax,double ay,char* fname,int size_x,int size_y,bool right);
	//関数
	/*
	引数のplayerのフィールド変数を変更して、アイテムの効果を与える関数
	*/
	public void Affect(Player player);
	/*
	そのアイテムがどのような思考をするか（動き方とか）を決定する
	*/
	public void Think();
	
protected:

	
private:


};