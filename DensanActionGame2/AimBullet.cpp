#include "AimBullet.h"


AimBullet::AimBullet(double x, double y,int damage, double move_power,double aim_x, double aim_y)
	:Bullet(x, y,damage,move_power, "Image/bullet1.png")
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
