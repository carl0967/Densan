/*
�L�����N�^�[���܂������������邾���̃R���g���[��
*/
#pragma once

#include "CharacterController.h"

class WalkStraight :public CharacterController{
public:
	WalkStraight(); //�������͎g��Ȃ�
	WalkStraight(Character* character); //�R���X�g���N�^
	void Think(); //���ۃN���X��Think�֐����I�[�o�[���C�h
};