#include "Bullet.h"


Bullet::Bullet(double x, double y,int damage,int speed, char* fname, int hit_size_x, int hit_size_y): AObject(x, y, fname,hit_size_x,hit_size_y,true)
{
	//�e�𔭎�
	Revival();
	//���ˈʒu�𒲐�
	pos_.x-=size_.x/2;
	pos_.y-=size_.y/2;
	//�X�s�[�h�ݒ�
	bullet_speed_ = speed;
	//�_���[�W�ݒ�
	damage_ = damage;
	//�����ݒ�
	this->right = false;
}

void Bullet::Initialize(double x, double y){
	Revival();
	pos_.x = x-size_.x/2;
	pos_.y = y-size_.y/2;
	first_pos_.x = pos_.x;
	first_pos_.y = pos_.y;
}

void Bullet::Think(){
	pos_.x += bullet_speed_*cos(angle_);
	pos_.y += bullet_speed_*sin(angle_);
}

void Bullet::DieBullet(){
	if( (pos_.x-first_pos_.x)>=640 || (pos_.x-first_pos_.x) <= -640 ||
		pos_.y<=-100 || pos_.y>=580){
			Die();
	}
}

Bullet::~Bullet(void)
{
}
