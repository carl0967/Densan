//#ifndef CHARACTER
//#define CHARACTER

#pragma once

#include "DxLib.h"
#include "AObject.h"
//#include "CharacterController.h"
class CharacterController;

class Character: public AObject{
public:
	Character(double x,double y); //コンストラクタ
	void Jump();   //ジャンプする
	void Walk(bool right); //right=true　なら右に、falseなら左に移動する
	void Run(bool right); //。Walkより速く移動する

	//void Set_Speed(double speed_x,double speed_y); //speedのセッター
	void NoMove(); //とまる
	void DoAttack(); //攻撃をする。未実装
	void Damaged(int damage);  //ダメージを受けるときに呼ばれる。HPが０になるとaliveがfalseに
	void Think(); //次にどのような行動をするかを決める。CharacterControllerに委譲。

protected:
	int hp_;  //体力
	int status_; //キャラクターの状態を表す
	CharacterController *controller_;


private:


};

//#endif