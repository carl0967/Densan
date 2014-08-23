#pragma once
#include "Attack.h"
#include "NormalBullet.h"
#include "Character.h"
class NormalAttack: public Attack
{
public:
	NormalAttack(int damage, int speed, int interval, Character* chara);
	NormalAttack(int damage, int speed, int interval, Character* chara, char* sound_name);
	void DoAttack();
	void InitializeBullet(int num);
	~NormalAttack(void);
};

