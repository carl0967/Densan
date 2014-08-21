#pragma once
#include "bullet.h"
class AimBullet :
	public Bullet
{
public:
	AimBullet(double x, double y,int damage, int speed, double hit_size_x, double hit_size_y,double aim_x, double aim_y);
	void Initialize(double x, double y, double aim_x, double aim_y);
	~AimBullet(void);
};

