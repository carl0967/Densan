#include "AimBullet.h"


AimBullet::AimBullet(double x, double y,int damage, double move_power, double hit_size_x, double hit_size_y,double aim_x, double aim_y)
	:Bullet(x, y,damage,move_power, "�摜/bullet1.png", hit_size_x, hit_size_y)
{
	angle_ = atan2(aim_y-y, aim_x-x);
}

void AimBullet::Initialize(double x, double y, double aim_x, double aim_y){
	Bullet::Initialize(x,y);
	angle_ = atan2(aim_y-y, aim_x-x);
}

AimBullet::~AimBullet(void)
{
}
