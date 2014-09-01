#include "Character.h"
#include "CharacterController.h"


Character::Character(double x,double y,double move_power,double jump_power,int hp,char* f_name,bool right,CharacterController* controller,Attack* attack)
	:AObject(x,y,move_power,f_name,right){
	hp_=hp;
	max_hp_=hp_;
	status_=0;
	attack_ = attack;
	controller_=controller;
	jump_power_=jump_power;
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
	if(right) speed_.x=move_power_;
	else speed_.x=-move_power_;
}
void Character::Run(bool right){
	if(right) speed_.x=move_power_*2;
	else speed_.x=-move_power_*2;
}
void Character::Jump(){
	speed_.y=-jump_power_;
	aerial=true;
}
void Character::Move(){
	AObject::Move();
	attack_->MoveBullets();
}
void Character::Think(){
	controller_->Think();
	attack_->ThinkBullets();
}

void Character::NoMove(){
	speed_.x=0;
}



void Character::Draw(int offset){
	AObject::Draw(offset);
	attack_->DrawBullets(offset);
}

vector<Bullet*> Character::GetBullets(){
	return attack_->bullets();
}

void Character::set_jump_power(double y){
	jump_power_=y;
}

//オーバーライド
void Character::Reset(){
	AObject::Reset();
	hp_ = max_hp_;
	attack_->ResetBullets();
}