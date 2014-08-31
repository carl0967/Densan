#pragma once
#include "item.h"
class Warp :
	public Item
{
public:
	Warp(double ax,double ay);
	void Affect(Character* character);
	void Think();
	~Warp(void);
};

