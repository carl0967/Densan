/*
Characterのコントローラ
キャラクターがどのように動くのかを決める部分
CharacterのThink関数の中で、このクラスのThinkが呼び出される

抽象クラス
*/
#ifndef CONTROLLER
#define CONTROLLER
#pragma once

#include "DxLib.h"

class Character;

class CharacterController{
public:
	CharacterController(); //こっちは使わない
	CharacterController(Character* character); //コンストラクタ
	virtual void Think()=0; //どのように動くかを決める
protected:
	Character* character_; //自身が持たれているキャラクターを参照
};

#endif