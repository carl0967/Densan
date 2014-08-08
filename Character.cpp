#include "Character.h"
#include "CharacterController.h"


Character::Character(double x,double y,char* f_name,int sizex,int sizey,bool r):AObject(x,y,f_name,sizex,sizey,r){
	hp_=10;
	status_=0;

}

void Character::Damaged(int damage){
	hp_-=damage;
	if(hp_<=0) alive=false;
}
void Character::Walk(bool right){
	if(right) speed_.x=1;
	else speed_.x=-1;
}
void Character::Run(bool right){
	if(right) speed_.x=2.5;
	else speed_.x=-2.5;
}
void Character::Jump(){
	speed_.y=-5;
	aerial=true;
}
void Character::Think(){
	controller_->Think();
}



void Character::NoMove(){
	speed_.x=0;
}