#pragma once
#include "charactercontroller.h"
class AttackBullet :
	public CharacterController
{
public:
	AttackBullet(Character* character,Field* field);
	void Think();
	~AttackBullet(void);
};

