/*
“GƒNƒ‰ƒX
*/
#pragma once

#include "Character.h"

class Enemy:public Character{
public:
	Enemy(double x,double y,int hp ,char* file_name,int size_x,int size_y,CharacterController* controller, Attack* attakck);
};
