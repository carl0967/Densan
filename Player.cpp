# include "Player.h"
#include "PlayerController.h"
#include "WalkStraight.h"

Player::Player(double x,double y,Field* field)
	:Character(x,y,5.0,15.0,5,"画像/witch1.png",1,1,true,new PlayerController(this,field), new NormalAttack(1,7,10,this,"音源/shot_sound.wav")){
	//初期化
	score_=0;
	life_=3;
	super_=false;
	super_count_=0;
	alive=true;
	move_ghandle_=loadg.Load("画像/witch2.png");
	object_type_ = O_PLAYER;
	game_status_=NOTHING;
	jump_sound_ = LoadSoundMem("音源/jump_sound.wav");
}

void Player::AddScore(int point){
	score_+=point;
}

void Player::SuperTime(){
	if(super_){
		super_count_++;
		if(super_count_>=50){
			super_count_=0;
			super_=false;
		}
	}
}

//オーバーライド
void Player::Jump(){
	speed_.y=-15;
	aerial=true;
	PlaySoundMem(jump_sound_,DX_PLAYTYPE_BACK);
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
	score_=0;
}

void Player::Draw(int offset){
	if(superCount()%2==0)
		AObject::Draw(offset);
	attack_->DrawBullets(offset);

}
