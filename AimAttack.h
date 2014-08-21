#pragma once
#include "attack.h"
#include "AimBullet.h"
#include "Character.h"

class AimAttack :
	public Attack
{
public:
	AimAttack(int damage, int speed, int interval, Character* chara);
	void InitializeBullet(int num);
	void DoAttack();
};

