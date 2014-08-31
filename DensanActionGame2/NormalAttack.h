#pragma once
#include "Attack.h"
#include "NormalBullet.h"
#include "Character.h"
class NormalAttack: public Attack
{
public:
	NormalAttack(int damage, double move_power, int interval, Character* chara);
	NormalAttack(int damage, double move_power, int interval, Character* chara, char* sound_name);
	void DoAttack();
	void InitializeBullet(int num);
	~NormalAttack(void);
};

