#include "NormalBullet.h"

NormalBullet::NormalBullet(double x, double y,int damage, int speed, double hit_size_x, double hit_size_y, bool right):Bullet(x, y,damage,speed, "‰æ‘œ/bullet1.png", hit_size_x, hit_size_y, right)
{
}

void NormalBullet::Think(){
	pos_.x += direction_*bullet_speed_;
}

NormalBullet::~NormalBullet(void)
{
}
