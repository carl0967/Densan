# include "Player.h"

Player::Player(double x,double y):Character(x,y){
	score_=0;
	life_=3;
}
void Player::addScore(int point){
	score_+=point;
}
//�I�[�o�[���C�h
void Player::init(){
	file_name="����2.png";
	size_.x=32;
	size_.y=32;
	right=false;
}

void Player::Think(){
		Walk(true);
}