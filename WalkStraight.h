/*
キャラクターをまっすぐ歩かせるだけのコントローラ
*/
#pragma once

#include "CharacterController.h"

class WalkStraight :public CharacterController{
public:
	WalkStraight(); //こっちは使わない
	WalkStraight(Character* character,Field* field); //コンストラクタ
	void Think(); //抽象クラスのThink関数をオーバーライド
};