/*
キャラクターをまっすぐ歩かせるだけのコントローラ
*/
#pragma once

#include "CharacterController.h"

class JumpEnemy :public CharacterController{
public:
	JumpEnemy(); //こっちは使わない
	JumpEnemy(Character* character,Field* field); //コンストラクタ
	void Think(); //抽象クラスのThink関数をオーバーライド
	void Jump();
private:	
	int count;//実行回数
	//bool EnemySightIn();//視界内にプレイヤーがいるか
};