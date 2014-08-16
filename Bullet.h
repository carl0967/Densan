#pragma once

//#include "DxLib.h"
#include "AObject.h"

/*
攻撃するための「弾」を表す抽象クラス
*/
/*
注意点
コンストラクタの引数にてダメージ設定を行うようにしています
*/

abstract class Bullet extends AObject{
public:
	//コンストラクタ
	//x座標、ｙ座標、ファイル名（画像/画像ファイル名,オブジェクトの幅,オブジェクトの高さ,向き（右向きならtrue）,ダメージ量
	Bullet(double ax,double ay,char* fname,int size_x,int size_y,bool right,int damageValue);
	//ゲッター
	/*
	フィールドに設定したダメージを返す
	*/
	int damage(){return damage;}
	//関数
	/*
	そのアイテムがどのような動きをするかを決定する
	基本的には自身のスピードを変更する
	サブクラスにて実装すること
	*/
	abstract void Think();
	
protected:

	//フィールド
	/*
	敵にぶつかった時にどれだけダメージを与えるのか
	*/
	int damage;

private:
	
};