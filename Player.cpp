# include "Player.h"
#include "PlayerController.h"
#include "WalkStraight.h"

Player::Player(double x,double y):Character(x,y,"‰æ‘œ/–‚—2.png",32,32,true){
	score_=0;
	life_=1;
	controller_=new PlayerController(this);
	//controller_=new WalkStraight(this);
	
}
void Player::addScore(int point){
	score_+=point;
}
