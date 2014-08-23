#include "Character.h"
#include "CharacterController.h"


Character::Character(double x,double y,int hp,char* f_name,int sizex,int sizey,bool right,CharacterController* controller,Attack* attack)
	:AObject(x,y,f_name,sizex,sizey,right){
	hp_=hp;
	max_hp_=hp_;
	status_=0;
	attack_ = attack;
	controller_=controller;
	jump_power=5.0;
}

Character::~Character(){
	delete controller_;
	delete attack_;
}

void Character::DoAttack(){
	attack_->DoAttack();
}

void Character::Damaged(int damage){
	hp_-=damage;
	if(hp_<=0) alive=false;
}
void Character::Walk(bool right){
	if(right) speed_.x=move_power;
	else speed_.x=-move_power;
}
void Character::Run(bool right){
	if(right) speed_.x=move_power*2;
	else speed_.x=-move_power*2;
}
void Character::Jump(){
	speed_.y=-jump_power;
	aerial=true;
}
void Character::Think(){
	controller_->Think();
	attack_->ThinkBullets();
}

void Character::NoMove(){
	speed_.x=0;
}

//オーバーライド
void Character::Reset(){
	AObject::Reset();
	hp_ = max_hp_;
	attack_->ResetBullets();
}

void Character::Draw(int offset){
	AObject::Draw(offset);
	attack_->DrawBullets(offset);
}

vector<Bullet*> Character::GetBullets(){
	return attack_->bullets();
}

void Character::set_jump_power(double y){
	jump_power=y;
}
