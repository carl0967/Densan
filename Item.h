#pragma once

#include "DxLib.h"

/*
物体である「アイテム」を表す抽象クラスのヘッダーファイル
担当:中井
*/
/*
更新:2014/07/07
更新内容:未作成状態から形を与えただけ
*/

abstract class Item extends AObject{
public:
	//フィールド

	//ゲッター
	
	//関数
	/*
	引数のcharacterのフィールド変数を変更して、アイテムの効果を与える関数
	サブクラスにて実装すること
	*/
	public abstract void Affect(Character character);
	/*
	オーバーライドした関数
	そのアイテムがどのような動きをするかを決定する
	基本的には自身のスピードを変更する
	サブクラスにて実装すること
	*/
	public abstract void Think();
	
protected:

	
private:


};