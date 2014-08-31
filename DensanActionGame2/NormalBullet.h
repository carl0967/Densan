#pragma once
#include "bullet.h"
#include <math.h>
class NormalBullet :
	public Bullet
{
public:
	NormalBullet(double x, double y,int damage, double move_power, double hit_size_x, double hit_size_y, bool right);
	void Initialize(double x, double y, bool right);
	~NormalBullet(void);
};

