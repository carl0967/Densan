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
	AimAttack(int damage, int speed, int interval, Character* chara, Character* aim_chara, char* sound_name);
	void DoAttack();
	void InitializeBullet(int num);
};

