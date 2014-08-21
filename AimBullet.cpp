#include "AimBullet.h"


AimBullet::AimBullet(double x, double y,int damage, int speed, double hit_size_x, double hit_size_y,double aim_x, double aim_y):Bullet(x, y,damage,speed, "�摜/normal_bullet.png", hit_size_x, hit_size_y)
{
	angle_ = atan2(aim_y-y, aim_x-x);
}

void AimBullet::Initialize(double x, double y, double aim_x, double aim_y){
	angle_ = atan2(aim_y-y, aim_x-x);
}

AimBullet::~AimBullet(void)
{
}
