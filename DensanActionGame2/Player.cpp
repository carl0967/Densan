# include "Player.h"
#include "PlayerController.h"
#include "WalkStraight.h"
#include <iostream>
#include <sstream>
#include <string>

Player::Player(double x,double y,Field* field)
	:Character(x,y,5.0,15.0,5,"Image/witch1.png",true,new PlayerController(this,field), new NormalAttack(1,7,10,this,"Sound/shot_sound.wav")){
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
	map_name_=field->GetMapName();
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
	//次のマップ名をstringで作成
	string str=map_name_;
	str.insert(8,"-");
	str.insert(9,(IntToString(next_map_count_)));

	//char型に変換
	 int len = str.length();
	char* c = new char[len+1];
	memcpy(c, str.c_str(), len+1);
	next_map_=c;


	next_map_flag_ = true;
	next_map_count_++;
	
}

string Player::IntToString(int number)
{
  stringstream ss;
  ss << number;
  return ss.str();
}
