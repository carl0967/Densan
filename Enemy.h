/*
�G�N���X
*/
#pragma once

#include "Character.h"

class Enemy:public Character{
public:
	//������x���W,y���W,�ړ����x,�W�����v��,HP,�摜�̃t�@�C����,�����蔻��̔{����X����,Y�����i1.0�����ʁj,����(�E��true),CharacterController,Attack
	Enemy(double x,double y,double move_power,double jump_power,int hp ,char* file_name,int size_x,int size_y,CharacterController* controller, Attack* attakck);
};
