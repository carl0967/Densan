//#ifndef PLAYER
//#define PLAYER

#pragma once

#include "DxLib.h"
#include "Character.h"


class Player: public Character{
public:
	Player(double x,double y);
	void addScore(int point);
	int score() {return score_;}
	int life(){return life_;}
protected:
	void init();
	CharacterController* CreateController();
private:
	int life_;  //プレイヤーの残機
	int score_; //得点

};

//#endif