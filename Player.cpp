# include "Player.h"
#include "PlayerController.h"
#include "WalkStraight.h"

Player::Player(double x,double y,Field* field):Character(x,y,"画像/魔女2.png",32,32,true){
	//初期化
	score_=0;
	life_=1;
	super_=false;
	super_count_=0;
	controller_=new PlayerController(this,field);
	//controller_=new WalkStraight(this);
	move_ghandle_=loadg.Load("画像/魔女3.png");
}

void Player::addScore(int point){
	score_+=point;
}

void Player::superTime(){
	if(super_){
		super_count_++;
		if(super_count_>=80){
			super_count_=0;
			super_=false;
		}
	}
}

//オーバーライド
void Player::Jump(){
	speed_.y=-15;
	aerial=true;
}
void Player::Damaged(int damage){
	Character::Damaged(damage);
	super_ = true;
}
void Player::Reset(){
	Character::Reset();
	super_ = false;
	super_count_ = 0;
	life_--;
}
