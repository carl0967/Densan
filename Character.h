#pragma once

#include "DxLib.h"
#include "AObject.h"

class Character: public AObject{
public:
	Character(double x,double y);
	void Jump();
	void Walk(bool right);
	void Run(bool right);

	void DoAttack();
	//ダメージを受けるときに呼ばれる。HPが０になるとaliveがfalseに
	void Damaged(int damage); 
	virtual void Think()=0;

protected:
	int hp_;  //体力
	int status_; //キャラクターの状態を表す

private:



};