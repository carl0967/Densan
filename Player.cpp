# include "Player.h"
#include "PlayerController.h"
#include "WalkStraight.h"

Player::Player(double x,double y,Field* field)
	:Character(x,y,50000,"�摜/����2.png",1,1,true,new PlayerController(this,field), new NormalAttack(1,7,10,this,"����/shot_sound.wav")){
	//������
	score_=0;
	life_=1;
	super_=false;
	super_count_=0;
	alive=true;
	move_ghandle_=loadg.Load("�摜/����3.png");
	object_type_ = O_PLAYER;
	game_status_=NOTHING;
	jump_sound_ = LoadSoundMem("����/jump_sound.wav");
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

//�I�[�o�[���C�h
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
}

void Player::Draw(int offset){
	if(superCount()%2==0)
		AObject::Draw(offset);
	attack_->DrawBullets(offset);
	DrawFormatString(100,100,GetColor(255,255,255),"%d",GetBulletsSize());

}
