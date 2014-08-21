#pragma once
#include "attack.h"
#include "AimBullet.h"
#include "Character.h"

class AimAttack :
	public Attack
{
private:
	Character* aim_chara_;
public:
	AimAttack(int damage, int speed, int interval, Character* chara, Character* aim_chara);
	void InitializeBullet(int num);
	void DoAttack();
};

