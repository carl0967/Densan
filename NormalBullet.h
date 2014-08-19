#pragma once
#include "bullet.h"
class NormalBullet :
	public Bullet
{
public:
	NormalBullet(double x, double y,int damage, int speed, double hit_size_x, double hit_size_y, bool right);
	void Think();
	~NormalBullet(void);
};

