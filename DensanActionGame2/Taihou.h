#pragma once
#include "enemy.h"
#include "AimAttack.h"
#include "AttackBullet.h"

class Filed;

class Taihou :
	public Enemy
{
public:
	Taihou(double x, double y, Field* field);
	~Taihou(void);
};

