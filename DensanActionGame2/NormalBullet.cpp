#include "NormalBullet.h"

NormalBullet::NormalBullet(double x, double y,int damage, double move_power,bool isRight)
	:Bullet(x, y,damage,move_power, "Image/bullet1.png")
{
	right = isRight;
	if(right) angle_ = 0*PAI/180;//�p�x��0�x�ɐݒ�
	else  angle_=180*PAI/180;//�p�x��180�x�ɐݒ�
}

void NormalBullet::Initialize(double x, double y, bool right){
	Bullet::Initialize(x,y);
	if(right) angle_ = 0*PAI/180;//�p�x��0�x�ɐݒ�
	else angle_=180*PAI/180;//�p�x��180�x�ɐݒ�
}

NormalBullet::~NormalBullet(void)
{
}
