# include "Player.h"
#include "PlayerController.h"
#include "WalkStraight.h"
#include "AimAttack.h"

Player::Player(double x,double y,Field* field)
	:Character(x,y,5,"画像/魔女2.png",1,1,true,new PlayerController(this,field), new NormalAttack(1,7,10,this)){
	//初期化
	score_=0;
	life_=1;
	super_=false;
	super_count_=0;
	clear=false;
	alive=true;
	move_ghandle_=loadg.Load("画像/魔女3.png");
	object_type_ = O_PLAYER;
	game_status_=NOTHING;
}

void Player::AddScore(int point){
	score_+=point;
}

void Player::SuperTime(){
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

void Player::Draw(int offset){
	if(superCount()%2==0)
		AObject::Draw(offset);
	attack_->DrawBullets(offset);

}
