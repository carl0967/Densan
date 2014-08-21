#include "NormalBullet.h"

NormalBullet::NormalBullet(double x, double y,int damage, int speed, double hit_size_x, double hit_size_y, bool right):Bullet(x, y,damage,speed, "�摜/normal_bullet.png", hit_size_x, hit_size_y)
{
	if(right)
		angle_ = 0*PAI/180;//�p�x��0�x�ɐݒ�
	else
		angle_=180*PAI/180;//�p�x��180�x�ɐݒ�
}

void NormalBullet::Initialize(double x, double y, bool right){
	Bullet::Initialize(x,y);
		if(right)
		angle_ = 0*PAI/180;//�p�x��0�x�ɐݒ�
	else
		angle_=180*PAI/180;//�p�x��180�x�ɐݒ�
}

NormalBullet::~NormalBullet(void)
{
}
