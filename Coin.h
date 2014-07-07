#pragma once

#include "DxLib.h"

/*
アイテムである「コイン」を表す具象クラスのヘッダーファイル
担当:中井
*/
/*
更新:2014/07/07
更新内容:未作成状態から形を与えただけ
*/

class Coin extends Item{
public:
	//フィールド

	//ゲッター
	
	//関数
	/*
	オーバーライドした関数
	引数のcharacterのフィールド変数を変更して、アイテムの効果を与える関数
	
	*/
	public void Affect(Character character){

	}
	/*
	オーバーライドした関数
	そのアイテムがどのような思考をするか（動き方とか）を決定する
	
	*/
	public void Think(){

	}
	
protected:

	
private:


};