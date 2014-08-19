#pragma once
#include "atack.h"
class NoAtack :
	public Atack
{
public:
	NoAtack(Character* chara);
	void DoAtack();
	~NoAtack(void);
};

