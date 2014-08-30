# include "Player.h"
#include "PlayerController.h"
#include "WalkStraight.h"
#include <iostream>
#include <sstream>

Player::Player(double x,double y,Field* field)
	:Character(x,y,5.0,15.0,5,"Image/witch1.png",1,1,true,new PlayerController(this,field), new NormalAttack(1,7,10,this,"Sound/shot_sound.wav")){
	//初期化
	score_=0;
	life_=3;
	super_=false;
	super_count_=0;
	alive=true;
	move_ghandle_=loadg.Load("Image/witch2.png");
	object_type_ = O_PLAYER;
	game_status_=NOTHING;
	jump_sound_ = LoadSoundMem("Sound/jump_sound.wav");
	next_map_flag_ = false;
	next_map_ = NULL;
	next_map_count_=1;
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

void Player::NextMapReset(double x, double y){
	first_pos_.x = x;
	first_pos_.y = y;
	pos_.x = x;
	pos_.y = y;
	next_map_flag_ = false;
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
	if(next_map_flag_){
		DrawCircle(100,10,10,GetColor(255,255,255),true);
	}
}

void Player::NextMap(){
	next_map_flag_ = true;
	next_map_count_++;
	switch(next_map_count_){
	case 1:
		next_map_ = "Map/map1.txt";
		break;
	case 2:
		next_map_ = "Map/map2.txt";
		break;
	case 3:
		next_map_ = "Map/map3.txt";
		break;
	case 4:
		next_map_ = "Map/map4.txt";
		break;
	case 5:
		next_map_ = "Map/map5.txt";
		break;
	case 6:
		next_map_ = "Map/map6.txt";
		break;
	case 7:
		next_map_ = "Map/map7.txt";
		break;

	}
	
}