#include "NormalBullet.h"

NormalBullet::NormalBullet(double x, double y,int damage, int speed, double hit_size_x, double hit_size_y, bool right):Bullet(x, y,damage,speed, "画像/normal_bullet.png", hit_size_x, hit_size_y)
{
	if(right)
		angle_ = 0*PAI/180;//角度を0度に設定
	else
		angle_=180*PAI/180;//角度を180度に設定
}

void NormalBullet::Initialize(double x, double y, bool right){
	Bullet::Initialize(x,y);
		if(right)
		angle_ = 0*PAI/180;//角度を0度に設定
	else
		angle_=180*PAI/180;//角度を180度に設定
}

NormalBullet::~NormalBullet(void)
{
}
