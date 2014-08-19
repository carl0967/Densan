#pragma once
#include "Attack.h"
#include "NormalBullet.h"
#include "Character.h"
class NormalAttack: public Attack
{
public:
	NormalAttack(int damage, int speed, int interval, Character* chara);
	void DoAttack();
	~NormalAttack(void);
};

