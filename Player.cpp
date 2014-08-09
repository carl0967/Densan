# include "Player.h"
#include "PlayerController.h"
#include "WalkStraight.h"

Player::Player(double x,double y,Field* field):Character(x,y,"�摜/����2.png",32,32,true){
	//������
	score_=0;
	life_=1;
	controller_=new PlayerController(this,field);
	//controller_=new WalkStraight(this);
	move_ghandle_=loadg.Load("�摜/����3.png");
	
}
void Player::addScore(int point){
	score_+=point;
}
//�I�[�o�[���C�h
void Player::Jump(){
	speed_.y=-5;
	aerial=true;
}
