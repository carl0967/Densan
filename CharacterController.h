/*
Characterのコントローラ
キャラクターがどのように動くのかを決める部分
CharacterのThink関数の中で、このクラスのThinkが呼び出される

抽象クラス
*/

#pragma once

#include "DxLib.h"
#include "Field.h"

class Character;

class CharacterController{
public:
	CharacterController(); //こっちは使わない
	CharacterController(Character* character,Field* field); //コンストラクタ
	virtual void Think()=0; //どのように動くかを決める。純粋仮想関数
protected:
	Character* character_; //自身が持たれているキャラクターを参照
	Field* field_;
};

