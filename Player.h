#pragma once

#include "DxLib.h"
#include "Character.h"

class Player: public Character{
public:
	Player(double x,double y);
	void addScore(int point);
	void Think();
	int score() {return score_;}
	int life(){return life_;}
protected:
	void init();
private:
	int life_;  //�v���C���[�̎c�@
	int score_; //���_

};