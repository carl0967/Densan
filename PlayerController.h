/*
Player用のコントローラ
キーボード入力によって動かす。
*/
#pragma once

#include "CharacterController.h"

class PlayerController :public CharacterController{
public:
	PlayerController(); //こっちは使わない
	PlayerController(Character* character); //コンストラクタ
	void Think(); //抽象クラスのThink関数をオーバーライド
};