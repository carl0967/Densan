/*
Player用のコントローラ
キーボード入力によって動かす。
*/
#pragma once

#include "CharacterController.h"

class PlayerController :public CharacterController{
public:
	PlayerController(); //こっちは使わない
	PlayerController(Character* character,Field* field); //コンストラクタ
	void Think(); //抽象クラスのThink関数をオーバーライド

private:
	char key[256];
	void UpdateKey();
};