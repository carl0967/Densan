#include "Bullet.h"


Bullet::Bullet(double x, double y,int damage,int speed, char* fname, int hit_size_x, int hit_size_y,bool right): AObject(x, y, fname,hit_size_x,hit_size_y,right)
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
	if(right)
		direction_ = RIGHT;
	else
		direction_ = LEFT;
}

void Bullet::Initialize(double x, double y, int direction){
	Revival();
	pos_.x = x-size_.x/2;
	pos_.y = y-size_.y/2;
	first_pos_.x = pos_.x;
	first_pos_.y = pos_.y;
	direction_ = direction;
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
