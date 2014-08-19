#pragma once
#include "Atack.h"
#include "NormalBullet.h"
#include "Character.h"
class NormalAtack: public Atack
{
public:
	NormalAtack(int damage, int speed, int interval, Character* chara);
	void DoAtack();
	~NormalAtack(void);
};

