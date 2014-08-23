#include "Bullet.h"


Bullet::Bullet(double x, double y,int damage,double move_power, char* fname, double hit_size_x, double hit_size_y): AObject(x, y,move_power, fname,hit_size_x,hit_size_y,true)
{
	//�e�𔭎�
	Revival();
	//���ˈʒu�𒲐�
	pos_.x-=size_.x/2;
	pos_.y-=size_.y/2;
	//�X�s�[�h�ݒ�
	//�_���[�W�ݒ�
	damage_=damage;
	//�����ݒ�
	this->right = false;
}

Bullet::~Bullet(){
}

void Bullet::Initialize(double x, double y){
	Revival();
	pos_.x = x-size_.x/2;
	pos_.y = y-size_.y/2;
	first_pos_.x = pos_.x;
	first_pos_.y = pos_.y;
}

void Bullet::Think(){
}

void Bullet::Move(){
	pos_.x += move_power_*cos(angle_);
	pos_.y += move_power_*sin(angle_);
}

void Bullet::DieBullet(){
	if( (pos_.x-first_pos_.x)>=640 || (pos_.x-first_pos_.x) <= -640 ||
		pos_.y<=-100 || pos_.y>=580){
			Die();
	}
}
