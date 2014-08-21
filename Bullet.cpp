#include "Bullet.h"


Bullet::Bullet(double x, double y,int damage,int speed, char* fname, int hit_size_x, int hit_size_y): AObject(x, y, fname,hit_size_x,hit_size_y,true)
{
	//弾を発射
	Revival();
	//発射位置を調整
	pos_.x-=size_.x/2;
	pos_.y-=size_.y/2;
	//スピード設定
	bullet_speed_ = speed;
	//ダメージ設定
	damage_ = damage;
	//方向設定
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
