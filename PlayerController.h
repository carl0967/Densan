#pragma once

#include "CharacterController.h"

class PlayerController :public CharacterController{
public:
	PlayerController();
	PlayerController(Character* character);
	void Think();
};