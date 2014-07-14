//#ifndef CHARACTER
//#define CHARACTER

#pragma once

#include "DxLib.h"
#include "AObject.h"
//#include "CharacterController.h"
class CharacterController;

class Character: public AObject{
public:
	Character(double x,double y);
	void Jump();
	void Walk(bool right);
	void Run(bool right);

	void DoAttack();
	//ダメージを受けるときに呼ばれる。HPが０になるとaliveがfalseに
	void Damaged(int damage); 
	void Think();

protected:
	int hp_;  //体力
	int status_; //キャラクターの状態を表す
	CharacterController *controller_;

	//自身が持つコントローラーを生成する
	//下位クラスでオーバーライドをする
	virtual CharacterController* CreateController(){return NULL;}

private:


};

//#endif