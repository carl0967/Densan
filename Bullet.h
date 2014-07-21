#pragma once

#include "DxLib.h"

/*
物体である「弾」を表す抽象クラスのヘッダーファイル
担当:中井
*/
/*
更新:2014/07/21
更新内容:未作成状態から形を与えただけ
*/

abstract class Bullet extends AObject{
public:
	//ゲッター
	/*

	*/
	int damage(){
		return damage;
	}
	//関数
	/*
	オーバーライドした関数
	そのアイテムがどのような動きをするかを決定する
	基本的には自身のスピードを変更する
	サブクラスにて実装すること
	*/
	public abstract void Think();
	
protected:

	
private:
	//フィールド
	/*
	敵にぶつかった時にどれだけダメージを与えるのか
	*/
	int damage;

};