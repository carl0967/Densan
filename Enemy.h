/*
“GƒNƒ‰ƒX
*/
#pragma once

#include "Character.h"

class Enemy:public Character{
public:
	Enemy(double x,double y,double move_power,double jump_power,int hp ,char* file_name,int size_x,int size_y,CharacterController* controller, Attack* attakck);
};
