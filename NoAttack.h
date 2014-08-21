#pragma once
#include "Attack.h"
class NoAttack :
	public Attack
{
public:
	NoAttack(Character* chara);
	void DoAttack();
	void InitializeBullet(int num);
	~NoAttack(void);
};

