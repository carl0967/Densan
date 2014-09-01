#pragma once
#include "bullet.h"
#include <math.h>
class NormalBullet :
	public Bullet
{
public:
	NormalBullet(double x, double y,int damage, double move_power, bool right);
	void Initialize(double x, double y, bool right);
	~NormalBullet(void);
};

