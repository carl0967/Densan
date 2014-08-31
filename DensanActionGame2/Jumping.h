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
	 int count_;//実行回数
	int jump_;//何回飛んだか
};