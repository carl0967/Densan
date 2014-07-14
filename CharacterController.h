#ifndef CONTROLLER
#define CONTROLLER
#pragma once

#include "DxLib.h"

class Character;

class CharacterController{
public:
	CharacterController();
	CharacterController(Character* character);
	virtual void Think()=0;
protected:
	Character* character_;
};

#endif