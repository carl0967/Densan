#include "Character.h"


Character::Character(double x,double y):AObject(x,y){
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
	if(right) speed_.x=5;
	else speed_.x=-5;
}
void Character::Jump(){
	speed_.y=-20;
}

