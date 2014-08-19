#pragma once
#include "Attack.h"
class NoAttack :
	public Attack
{
public:
	NoAttack(Character* chara);
	void DoAttack();
	~NoAttack(void);
};

