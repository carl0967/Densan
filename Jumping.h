/*
キャラクターをまっすぐ歩かせるだけのコントローラ
*/
#pragma once
#include "WalkStraight.h"

class Jumping :public WalkStraight{
public:
	Jumping(); //こっちは使わない
	Jumping(Character* character,Field* field); //コンストラクタ
	void Think(); //抽象クラスのThink関数をオーバーライド
	void Jump();
private:	
	static const int count=0;//実行回数
	static const int jump=0;//何回飛んだか
};