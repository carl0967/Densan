# include "Player.h"
#include "PlayerController.h"
#include "WalkStraight.h"

Player::Player(double x,double y):Character(x,y,"画像/魔女2.png",32,32,true){
	//初期化
	score_=0;
	life_=1;
	controller_=new PlayerController(this);
	//controller_=new WalkStraight(this);
	move_ghandle_=loadg.Load("画像/魔女3.png");
	
}
void Player::addScore(int point){
	score_+=point;
}
//オーバーライド
void Player::Jump(){
	speed_.y=-5;
	aerial=true;
}
