#include "NormalBullet.h"

NormalBullet::NormalBullet(double x, double y,int damage, double move_power, double hit_size_x, double hit_size_y, bool isRight)
	:Bullet(x, y,damage,move_power, "Image/bullet1.png", hit_size_x, hit_size_y)
{
	right = isRight;
	if(right) angle_ = 0*PAI/180;//角度を0度に設定
	else  angle_=180*PAI/180;//角度を180度に設定
}

void NormalBullet::Initialize(double x, double y, bool right){
	Bullet::Initialize(x,y);
	if(right) angle_ = 0*PAI/180;//角度を0度に設定
	else angle_=180*PAI/180;//角度を180度に設定
}

NormalBullet::~NormalBullet(void)
{
}
